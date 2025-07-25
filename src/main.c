/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:45:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/25 11:43:35 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->config.texture_north = NULL;
	data->config.texture_south = NULL;
	data->config.texture_west = NULL;
	data->config.texture_est = NULL;
	data->config.floor_color = -1;
	data->config.ceiling_color = -1;
	data->config.texture_north_img = NULL;
	data->config.texture_south_img = NULL;
	data->config.texture_west_img = NULL;
	data->config.texture_est_img = NULL;
	data->config.last_wall_hit = 0;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player.pos[0] = 0;
	data->player.pos[1] = 0;
	data->player.dir[0] = 0;
	data->player.dir[1] = 0;
	data->player.plane[0] = 0;
	data->player.plane[1] = 0;
	data->player.turnDirection = 0;
	data->player.walkDirection = 0;
	data->player.moveSpeed = 4.0;
	data->player.rotationSpeed = 0.1;
	data->player.direction = '\0';
	data->player.texture_player = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*map;
	int		r;

	map = NULL;
	if (ac != 2 || !check_file_extension(av[1]))
		return (printf("usage: %s <map.cub>\n", av[0]), 1);
	init_data(&data);
	if (parse_file(av[1], &data))
	{
		cleanup_data(&data);
		return (1);
	}
	if (!check_map(&data))
	{
		cleanup_data(&data);
		return (1);
	}
	printf("Carte valide !\n");
	init_player(&data);
	data.mlx = mlx_init();
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.mlx)
	{
		cleanup_data(&data);
		return (printf("Mlx failed to create\n"), 1);
	}
	r = gamemlx(&data, map, av);
	if (r != 1)
	{
		cleanup_data(&data);
		return (1);
	}
	render_map(&data);
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_input, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	cleanup_data(&data);
	return (0);
}
