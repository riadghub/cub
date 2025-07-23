/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:53:32 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/22 14:20:30 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SIZE2 100

void	draw_line(t_img *img, int beginX, int beginY, int endX, int endY,
		int color)
{
	int	pixels;

	double deltaX, deltaY;
	double pixelX, pixelY;
	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	if (pixels == 0)
		return ;
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while (pixels > 0)
	{
		put_pixel_to_image(img, (int)pixelX, (int)pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
}

double	get_rotation_angleY(t_data *data)
{
	return (sin(data->player.rotationAngle) * SIZE2 + data->player.y);
}

double	get_rotation_angleX(t_data *data)
{
	return (cos(data->player.rotationAngle) * SIZE2 + data->player.x);
}
