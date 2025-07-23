/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:41:33 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/22 13:50:50 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# define __USE_MISC
# include "../get_next_line/get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "raycast.h"
# include "vectors.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EQUAL =

typedef struct s_config
{
	void		*wall;
	void		*floor;
	char		*texture_north;
	char		*texture_south;
	char		*texture_west;
	char		*texture_est;
	int			floor_color;
	int			ceiling_color;
}				t_config;

typedef struct s_player
{
	double		x;
	double		y;
	int			turnDirection;
	int			walkDirection;
	double		rotationSpeed;
	double		rotationAngle;
	double		moveSpeed;
	char direction; // N, S, E, W
	char		*texture_player;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_config	config;
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	t_ray		*ray;
	t_img		*img;
}				t_data;

// ========== FONCTIONS DEV ==========

// void	print_texture(char *name, char *texture);
// void	print_textures(t_config *config);
// void	print_config(t_config *config);
// void	print_map(t_data *data);

// ========== FONCTIONS DE PARSING ==========
int				parse_file(const char *filename, t_data *data);
int 			process_line(char *line, t_data *data);
int				is_color_line(char *line);
int				get_rgb_value(char *rgb_str);
int				convert_rgb(char *line);
int 			parse_color_line(char *line, t_config *config);
int				is_texture_line(char *line);
int				parse_texture_line(char *line, t_config *config);
char 			*extract_texture_path(char *trimmed);
int 			assign_texture(char *trimmed, char *path, t_config *config);
int 			assign_texture_by_direction(t_config *config, char *path, char *direction);
int				is_map_line(char *line);
int 			validate_order(t_data *data);

// ========== FONCTIONS DE GESTION DE CARTE ==========
void			add_map_line(t_data *data, char *line);
void			cleanup_map(t_data *data);
int				find_player(t_data *data);

// ========== FONCTIONS DE VALIDATION ==========
int				check_walls(t_data *data);
int				check_spaces(t_data *data);
int				check_path(t_data *data);
int				check_files(t_config *config);
int				check_map(t_data *data);
int				check_content(t_data *data);

// ========== FONCTIONS PRINCIPALES ==========
void			init_data(t_data *data);
int				check_file_extension(char *filename);
void			cleanup_data(t_data *data);
int				main_loop(t_data *game);

// Validation des bordures
int				check_line(t_data *data, int line_index);
int				check_sides(t_data *data, int i);
int				check_walls(t_data *data);

// Validation des espaces
int				check_pos(t_data *data, int x, int y);
int				check_around(t_data *data, int x, int y);
int				check_spaces(t_data *data);

// Flood fill algorithm
int				is_border(t_data *data, int x, int y);
void			flood_fill(char **map, int x, int y, t_data *data, int *valid);
char			**copy_map(t_data *data);
void			free_copy(char **map, int height);
int				get_max_width(t_data *data);

// Validation des fichiers
int				file_exists(char *filename);
int				check_files(t_config *config);

#endif
