/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:30:05 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/23 14:12:48 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int key, t_data *game)
{
	if (key == 65307)
		close_game(game);
	if (key == MOVE_UP || key == ARROW_UP)
		update(key, game);
	if (key == MOVE_LEFT || key == ARROW_LEFT)
		update(key, game);
	if (key == MOVE_RIGHT || key == ARROW_RIGHT)
		update(key, game);
	if (key == MOVE_DOWN || key == ARROW_DOWN)
		update(key, game);
	return (0);
}

int	close_game(t_data *game)
{
	// free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map)
		free_split(game->map);
	exit(0);
	return (0);
}

int	main_loop(t_data *game)
{
	render_map(game);
	usleep(10);
	return (0);
}
