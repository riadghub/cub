/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:25:07 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/25 11:46:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_column(t_data *game, int x, double distance)
{
	double	line_height;
	double	exact_start;
	double	exact_end;
	int		draw_start;
	int		draw_end;
	double	wall_ratio;
	int		wall_color;

	line_height = (double)WINDOW_HEIGHT / distance * TILESIZE;
	exact_start = ((double)WINDOW_HEIGHT - line_height) / 2.0;
	exact_end = exact_start + line_height;
	draw_start = (int)(exact_start);
	draw_end = (int)(exact_end + 0.999); // arrondi vers le haut
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT;
	wall_ratio = 1.0 - (distance / (TILESIZE * 20));
	if (wall_ratio < 0.3)
		wall_ratio = 0.3;
	wall_color = darken_color(0x3b2b65, wall_ratio);
	draw_line(game, x, 0, x, draw_start, 0x9eedfc);
	draw_line(game, x, draw_start, x, draw_end, wall_color);
	draw_line(game, x, draw_end, x, WINDOW_HEIGHT, 0xcfcfcf);
}

void	render(t_data *game)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	distance;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		ray_dir_x = game->player.dir[0] + game->player.plane[0] * camera_x;
		ray_dir_y = game->player.dir[1] + game->player.plane[1] * camera_x;
		distance = cast_ray_dda(game, ray_dir_x, ray_dir_y);
		draw_wall_column(game, x, distance);
		x++;
	}
}
double	cast_ray_dda(t_data *game, double ray_dir_x, double ray_dir_y)
{
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;

	hit = 0;
	side = 0;
	map_x = (int)(game->player.pos[0] / TILESIZE);
	map_y = (int)(game->player.pos[1] / TILESIZE);
	if (ray_dir_x == 0)
		delta_dist_x = 1e30;
	else
		delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		delta_dist_y = 1e30;
	else
		delta_dist_y = fabs(1 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (game->player.pos[0] / TILESIZE - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - game->player.pos[0] / TILESIZE)
			* delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (game->player.pos[1] / TILESIZE - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - game->player.pos[1] / TILESIZE)
			* delta_dist_y;
	}
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_x < 0 || map_x >= game->map_width || map_y < 0
			|| map_y >= game->map_height || game->map[map_y][map_x] == '1')
		{
			hit = 1;
		}
	}
	if (side == 0) // Vertical wall (North-South facing)
	{
		if (step_x > 0)
			game->config.last_wall_hit = 2;
		// West (we hit the west side of a wall)
		else
			game->config.last_wall_hit = 3;
		// East (we hit the east side of a wall)
	}
	else // Horizontal wall (East-West facing)
	{
		if (step_y > 0)
			game->config.last_wall_hit = 0;
		// North (we hit the north side of a wall)
		else
			game->config.last_wall_hit = 1;
		// South (we hit the south side of a wall)
	}
	if (side == 0)
		perp_wall_dist = (map_x - game->player.pos[0] / TILESIZE + (1 - step_x)
				/ 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - game->player.pos[1] / TILESIZE + (1 - step_y)
				/ 2) / ray_dir_y;
	return (perp_wall_dist * TILESIZE);
}
