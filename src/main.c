/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:45:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/22 13:50:02 by reeer-aa         ###   ########.fr       */
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
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_ray	ray;
	char	*map;
	int		r;

	map = NULL;
	if (ac != 2 || !check_file_extension(av[1]))
		return (printf("usage: %s <map.cub>\n", av[0]), 1);
	init_data(&data);
	if (parse_file(av[1], &data))
	{
		//printf("Erreur pendant le parsing\n");
		cleanup_data(&data);
		return (1);
	}
	//printf("Parsing terminé\n");
	if (!check_map(&data))
	{
		cleanup_data(&data);
		return (1);
	}
	printf("Carte valide !\n");
	printf("TOOOOOZZZZZZ !\n");
	data.ray = &ray;
	ray.game = &data;
	init_player(&data);
	init_ray(&data, 60);
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
		if (r == -1)
			return (1);
		return (1);
	}
	//printf("Has Wall At : %d\n", has_wall_at(&data, 1, 1));
	render_map(&data);
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_input, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	cleanup_data(&data);
	return (0);
}

