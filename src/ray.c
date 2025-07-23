/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:25:07 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/23 14:34:48 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	init_ray(t_data *game, double angle)
{
	game->ray->ray_angle = normalize_angle(angle);
}

static void	setup_ray(t_ray *ray, int i)
{
	ray->ray_angle = ray->start_angle + i * ray->angle_step;
	ray->ray_angle = normalize_angle(ray->ray_angle);
	ray->step_x = cos(ray->ray_angle) * 0.05;
	ray->step_y = sin(ray->ray_angle) * 0.05;
	ray->end_x = ray->game->player.x;
	ray->end_y = ray->game->player.y;
}

static void	cast_single_ray(t_ray *ray, int i)
{
	int	steps;
	int	max_distance;
	int	map_x;
	int	map_y;

	max_distance = 99999;
	setup_ray(ray, i);
	steps = 0;
	while (steps < max_distance)
	{
		ray->end_x += ray->step_x;
		ray->end_y += ray->step_y;
		map_x = (int)(ray->end_x / TILESIZE);
		map_y = (int)(ray->end_y / TILESIZE);
		if (map_x < 0 || map_x >= WINDOW_WIDTH || map_y < 0
			|| map_y >= WINDOW_HEIGHT || ray->game->map[map_y][map_x] == '1')
		{
			ray->distance = sqrt(pow(ray->end_x - ray->game->player.x, 2)
					+ pow(ray->end_y - ray->game->player.y, 2));
			break ;
		}
		steps++;
	}
}

static void	draw_wall_column(t_ray *ray, int i)
{
	double	line_height;
	int		draw_begin;
	int		draw_end;
	double	angle_diff;

	angle_diff = ray->ray_angle - ray->game->player.rotationAngle;
	ray->distance = ray->distance * cos(angle_diff);
	line_height = (double)(64 / ray->distance) * D;
	draw_begin = (WINDOW_HEIGHT / 2) - (line_height / 2);
	draw_end = draw_begin + line_height;
	if (draw_begin < 0)
		draw_begin = 0;
	if (draw_end > WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT;
	draw_line(ray->game->img, i, 0, i, draw_begin - 1, 0x9eedfc);
	// CIEL
	draw_line(ray->game->img, i, draw_end + 1, i, WINDOW_HEIGHT - 1, 0xcfcfcf);
	// SOL
	draw_line(ray->game->img, i, draw_begin, i, draw_end, 0x3b2b65);
	// MUR
}

void	render(t_ray *ray)
{
	int	i;

	ray->start_angle = ray->game->player.rotationAngle - (FOV / 2);
	ray->angle_step = FOV / NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		cast_single_ray(ray, i);
		draw_wall_column(ray, i);
		i++;
	}
}
