/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 05:18:57 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/24 05:18:58 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_size(t_data *game)
{
    game->map_height = 0;
    while (game->map[game->map_height])
        game->map_height++;
    if (game->map[0])
        game->map_width = ft_strlen(game->map[0]);
    else
        game->map_width = 0;
}

int gamemlx(t_data *game, char *map, char *argv[])
{
    (void)map;
    (void)argv;
    
    if (!game->mlx)
        return (printf("Error: Failed to initialize MiniLibX\n"), 0);
    init_size(game);
    if (!load_all_textures(game))
    {
        free_textures(game);
        destroy_all(game);
        return (0);
    }
    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
    if (!game->win)
        return (printf("Error: Failed to create window\n"), 0);    
    return (1);
}

void render_map(t_data *game)
{
    render(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void	destroy_all(t_data *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
