/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 05:20:16 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/24 05:20:17 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color_line(char *line)
{
	if (!line)
		return (0);
	return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	get_rgb_value(char *rgb_str)
{
	char	*temp;
	int		value;

	temp = ft_strtrim(rgb_str, " \t\n");
	value = ft_atoi(temp);
	free(temp);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

int convert_rgb(char *line)
{
    char **rgb;
    int color;
    int r, g, b;
    
    rgb = ft_split(line, ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
    {
        if (rgb)
            free_split(rgb);
        return (-1);
    }
    
    r = get_rgb_value(rgb[0]);
    g = get_rgb_value(rgb[1]);
    b = get_rgb_value(rgb[2]);
    
    if (r == -1 || g == -1 || b == -1)
    {
        free_split(rgb);
        return (-1);
    }
    
    color = (r * 65536) + (g * 256) + b;
    free_split(rgb);
    return (color);
}

int parse_color_line(char *line, t_config *config)
{
    char *color_part;
    int color_value;
    
    color_part = ft_strchr(line, ' ');
    if (!color_part)
        return (printf("Erreur : ligne de couleur invalide.\n"), 0);
    
    color_part += 1;
    color_part = ft_strtrim(color_part, " \t\n");
    color_value = convert_rgb(color_part);
    free(color_part);
    
    if (color_value == -1)
        return (printf("Erreur : couleur invalide.\n"), 0);
    
    if (line[0] == 'F')
        config->floor_color = color_value;
    else if (line[0] == 'C')
        config->ceiling_color = color_value;
    
    return (1);
}
