/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 05:19:58 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/24 05:19:59 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_texture_line(char *line)
{
    char *trimmed;
    int result;
    
    if (!line)
        return (0);
    
    trimmed = ft_strtrim(line, " \t\n");
    if (!trimmed)
        return (0);
    
    result = 0;
    if (ft_strncmp(trimmed, "NO ", 3) == 0)
        result = 1;
    else if (ft_strncmp(trimmed, "SO ", 3) == 0)
        result = 1;
    else if (ft_strncmp(trimmed, "WE ", 3) == 0)
        result = 1;
    else if (ft_strncmp(trimmed, "EA ", 3) == 0)
        result = 1;
    
    free(trimmed);
    return (result);
}

int parse_texture_line(char *line, t_config *config)
{
    char *path;
    char *trimmed;

    trimmed = ft_strtrim(line, " \t\n");
    if (!trimmed)
        return (0);

    path = extract_texture_path(trimmed);
    if (!path)
    {
        free(trimmed);
        return (0);
    }

    if (!assign_texture_by_direction(config, path, trimmed))
    {
        free(path);
        free(trimmed);
        return (0);
    }

    free(trimmed);
    return (1);
}

char *extract_texture_path(char *trimmed)
{
    char *path;

    path = ft_strchr(trimmed, ' ');
    if (!path)
    {
        printf("Erreur : ligne de texture invalide.\n");
        return (NULL);
    }
    path += 1;
    return (ft_strtrim(path, " \t\n"));
}

int assign_texture(char *trimmed, char *path, t_config *config)
{
    return (assign_texture_by_direction(config, path, trimmed));
}

int assign_texture_by_direction(t_config *config, char *path, char *direction)
{
    if (ft_strncmp(direction, "NO", 2) == 0)
    {
        if (config->texture_north)
            return (printf("Error: Duplicate North texture\n"), 0);
        config->texture_north = path;
    }
    else if (ft_strncmp(direction, "SO", 2) == 0)
    {
        if (config->texture_south)
            return (printf("Error: Duplicate South texture\n"), 0);
        config->texture_south = path;
    }
    else if (ft_strncmp(direction, "WE", 2) == 0)
    {
        if (config->texture_west)
            return (printf("Error: Duplicate West texture\n"), 0);
        config->texture_west = path;
    }
    else if (ft_strncmp(direction, "EA", 2) == 0)
    {
        if (config->texture_est)
            return (printf("Error: Duplicate East texture\n"), 0);
        config->texture_est = path;
    }
    else
        return (0);
    return (1);
}
