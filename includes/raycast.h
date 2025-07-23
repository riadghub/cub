/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:29:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/23 11:16:36 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "mlx_int.h"
# include <math.h>

# define TILESIZE 48
# define ROWS 10
# define COLS 15
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define D WINDOW_WIDTH / (tan(30))
# define FOV 90 * (M_PI / 180)
# define RES 1
# define NUM_RAYS WINDOW_WIDTH
# define WALL_PATH "textures/wall.xpm"
# define FLOOR_PATH "textures/tile.xpm"
# define PLAYER_PATH "textures/red_dot.xpm"

typedef struct s_data	t_data;

typedef struct s_ray
{
	double				x;
	double				y;
	double				distance;
	double				start_angle;
	double				angle_step;
	double				ray_angle;
	double				end_x;
	double				end_y;
	double				step_x;
	double				step_y;
	t_data				*game;
}						t_ray;

int						close_game(t_data *game);
int						has_wall_at(t_data *game, int x, int y);
int						handle_input(int key, t_data *game);
int						gamemlx(t_data *game, char *map, char *argv[]);
int						load_all_textures(t_data *game);
void					destroy_all(t_data *game);
void					free_textures(t_data *game);
void					init_player(t_data *game);
void					init_ray(t_data *game, double angle);
void					*load_texture(void *mlx, char *path);
void					rendering(t_data *game, int x);
void					render_map(t_data *game);
void					render(t_ray *ray);

int						init_main_image(t_data *game);
void					put_pixel_to_image(t_img *img, int x, int y, int color);
void					put_image_to_image(t_img *dst, t_img *src, int x,
							int y);

#endif