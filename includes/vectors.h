#ifndef VECTORS_H
# define VECTORS_H

# include "cub3d.h"
# include <math.h>

# define MOVE_UP 'w'
# define MOVE_DOWN 's'
# define MOVE_LEFT 'a'
# define MOVE_RIGHT 'd'
# define ARROW_UP XK_Up       // = 65362
# define ARROW_DOWN XK_Down   // = 65364
# define ARROW_LEFT XK_Left   // = 65361
# define ARROW_RIGHT XK_Right // = 65363

void draw_line(t_data *game, int beginX, int beginY, int endX, int endY, int color);
void	update(int key, t_data *game);
void 	rotate_player(t_data *game, double angle);

double	get_rotation_angleY(t_data *data);
double	get_rotation_angleX(t_data *data);

#endif