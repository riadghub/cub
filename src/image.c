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

void put_pixel(t_data *game, int x, int y, int color)
{
    char *dst;
    int bits_per_pixel;
    int line_length;
    int endian;
    
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
        return;
    
    dst = mlx_get_data_addr(game->img, &bits_per_pixel, &line_length, &endian);
    dst += (y * line_length + x * (bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int blend_colors(int color1, int color2, double alpha)
{
    int r1;
    int g1;
    int b1;
    int r2;
    int g2;
    int b2;
    int r;
    int g;
    int b;
    
    r1 = (color1 >> 16) & 0xFF;
    g1 = (color1 >> 8) & 0xFF;
    b1 = color1 & 0xFF;
    
    r2 = (color2 >> 16) & 0xFF;
    g2 = (color2 >> 8) & 0xFF;
    b2 = color2 & 0xFF;
    
    r = (int)(r1 * (1 - alpha) + r2 * alpha);
    g = (int)(g1 * (1 - alpha) + g2 * alpha);
    b = (int)(b1 * (1 - alpha) + b2 * alpha);
    
    return (r << 16) | (g << 8) | b;
}

int darken_color(int original_color, double ratio)
{
    int r;
    int g;
    int b;
    
    r = ((original_color >> 16) & 0xFF) * ratio;
    g = ((original_color >> 8) & 0xFF) * ratio;
    b = (original_color & 0xFF) * ratio;
    
    return (r << 16) | (g << 8) | b;
}
