/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:33:27 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/23 10:09:10 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_main_image(t_data *game)
{
	game->img = (t_img *)mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
		return (0);
	return (1);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	offset;

	if (!img || !img->data || x < 0 || y < 0 || x >= WINDOW_WIDTH
		|| y >= WINDOW_HEIGHT)
		return ;
	offset = (y * img->size_line / 4) + (x);
	((int *)img->data)[offset] = color;
}

void	put_image_to_image(t_img *dst, t_img *src, int x, int y)
{
	int	xs;
	int	ys;

	xs = 0;
	while (xs <= src->width)
	{
		ys = 0;
		while (ys <= src->height)
		{
			if (xs + x > dst->width || ys + y > dst->height)
				continue ;
			((unsigned int *)dst->data)[(ys + y) * (dst->size_line / 4) + xs
				+ x] = ((unsigned int *)src->data)[(ys) * (src->size_line / 4)
				+ xs];
			ys++;
		}
		xs++;
	}
}
