/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:25:07 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/23 14:05:58 by reeer-aa         ###   ########.fr       */
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
	ray->end_x = ray->game->player.x;
	ray->end_y = ray->game->player.y;
}

static void	cast_single_ray(t_ray *ray, int i)
{
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	setup_ray(ray, i);
	map_x = (int)(ray->end_x / TILESIZE);
	map_y = (int)(ray->end_y / TILESIZE);
	
	// Calculate delta distances
	if (fabs(cos(ray->ray_angle)) < 1e-10)
		delta_dist_x = 1e30;
	else
		delta_dist_x = fabs(1 / cos(ray->ray_angle));
	if (fabs(sin(ray->ray_angle)) < 1e-10)
		delta_dist_y = 1e30;
	else
		delta_dist_y = fabs(1 / sin(ray->ray_angle));
	
	// Calculate step direction and initial sideDist
	if (cos(ray->ray_angle) < 0)
	{
		step_x = -1;
		side_dist_x = (ray->end_x / TILESIZE - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - ray->end_x / TILESIZE) * delta_dist_x;
	}
	if (sin(ray->ray_angle) < 0)
	{
		step_y = -1;
		side_dist_y = (ray->end_y / TILESIZE - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - ray->end_y / TILESIZE) * delta_dist_y;
	}
	
	// Perform DDA
	hit = 0;
	int max_iterations = 1000; // Safety limit
	while (hit == 0 && max_iterations > 0)
	{
		// Jump to next map square, either in x-direction, or in y-direction
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
		// Check if ray has hit a wall
		if (has_wall_at(ray->game, map_x, map_y))
			hit = 1;
		max_iterations--;
	}
	
	// Calculate distance
	if (side == 0)
	{
		if (fabs(cos(ray->ray_angle)) < 1e-10)
			ray->distance = 1e30;
		else
			ray->distance = (map_x - ray->end_x / TILESIZE + (1 - step_x) / 2) / cos(ray->ray_angle);
	}
	else
	{
		if (fabs(sin(ray->ray_angle)) < 1e-10)
			ray->distance = 1e30;
		else
			ray->distance = (map_y - ray->end_y / TILESIZE + (1 - step_y) / 2) / sin(ray->ray_angle);
	}
		
	// Make distance positive and scale
	ray->distance = fabs(ray->distance * TILESIZE);
	
	// Ensure distance is reasonable
	if (ray->distance > 10000)
		ray->distance = 10000;
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
	if (draw_end > WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT;
	draw_line(ray->game->img, i, 0, i, draw_end, 0x9eedfc);
	// CIEL
	draw_line(ray->game->img, i, draw_end + 1, i, WINDOW_HEIGHT, 0xcfcfcf);
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
