/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:42:11 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/13 16:42:12 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_line(t_data *data, int line_index)
{
    int j;
    char *line;
    int len;

    line = data->map[line_index];
    len = ft_str_len(line);
    if (len < 3)
    {
        //printf("Error: Border line %d too short: minimum 3 characters required\n", 
            //line_index + 1);
        return (0);
    }
    
    j = 0;
    while (line[j])
    {
        if (line[j] != '1' && line[j] != ' ')
            return (0);
        j++;
    }
    return (1);
}

int	check_sides(t_data *data, int i)
{
	int	j;
	int	len;

	j = 0;
	while (data->map[i][j] == ' ')
		j++;
	if (data->map[i][j] && data->map[i][j] != '1')
		return (0);
	len = ft_str_len(data->map[i]);
	j = len - 1;
	while (j >= 0 && data->map[i][j] == ' ')
		j--;
	if (j >= 0 && data->map[i][j] != '1')
		return (0);
	return (1);
}

int check_walls(t_data *data)
{
	int i;

	if (!check_line(data, 0))
		return (printf("Error: First line of map must contain only walls (1) and spaces\n"), 0);
	if (!check_line(data, data->map_height - 1))
		//return (printf("Error: Last line of map must contain only walls (1) and spaces\n"), 0);
		return(0);
	i = 1;
	while (i < data->map_height - 1)
	{
		if (!check_sides(data, i))
			return (printf("Error: Map not closed: line %d borders must be walls (1)\n", i + 1), 0);
		i++;
	}
	return (1);
}

int	check_pos(t_data *data, int x, int y)
{
	if (y < 0 || y >= data->map_height)
		return (1);
	if (x < 0 || x >= (int)ft_str_len(data->map[y]))
		return (1);
	if (data->map[y][x] != '1' && data->map[y][x] != ' ')
		return (0);
	return (1);
}

int	check_around(t_data *data, int x, int y)
{
	if (!check_pos(data, x - 1, y))
		return (0);
	if (!check_pos(data, x + 1, y))
		return (0);
	if (!check_pos(data, x, y - 1))
		return (0);
	if (!check_pos(data, x, y + 1))
		return (0);
	return (1);
}

int check_spaces(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
			{
				if (!check_around(data, x, y))
				{
					printf("Error: Invalid space at line %d, column %d: spaces must be surrounded by walls or other spaces\n", 
						y + 1, x + 1);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	file_exists(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int check_files(t_config *config)
{
	if (!file_exists(config->texture_north))
		return (printf("Error: North texture file not found: %s\n", config->texture_north), 0);
	if (!file_exists(config->texture_south))
		return (printf("Error: South texture file not found: %s\n", config->texture_south),0);
	if (!file_exists(config->texture_west))
		return (printf("Error: West texture file not found: %s\n", config->texture_west),0);
	if (!file_exists(config->texture_est))
		return (printf("Error: East texture file not found: %s\n", config->texture_est),0);
	return (1);
}

int check_player_not_trapped(t_data *data)
{
	int x;
	int y;
	int accessible_neighbors;

	x = data->player.x;
	y = data->player.y;
	accessible_neighbors = 0;

	if (x > 0 && data->map[y][x - 1] == '0')
		accessible_neighbors++;
	if (x < (int)ft_str_len(data->map[y]) - 1 && data->map[y][x + 1] == '0')
		accessible_neighbors++;
	if (y > 0 && data->map[y - 1][x] == '0')
		accessible_neighbors++;
	if (y < data->map_height - 1 && data->map[y + 1][x] == '0')
		accessible_neighbors++;

	if (accessible_neighbors == 0)
		return (printf("Error: Player is trapped: no accessible spaces around player position\n"), 0);
	return (1);
}

int check_map(t_data *data)
{
	if (!data->map || data->map_height == 0)
		return (printf("Error: Empty map\n"), 0);
	if (data->config.floor_color == -1)
		return (printf("Error: Missing floor color (F)\n"), 0);
	if (data->config.ceiling_color == -1)
		return (printf("Error: Missing ceiling color (C)\n"), 0);
	if (!data->config.texture_north || !data->config.texture_south || 
			!data->config.texture_west || !data->config.texture_est)
		return (printf("Error: Missing texture(s)\n"), 0);
	if (!check_content(data))
		return (printf("Error: Invalid characters in map\n"), 0);
	if (!find_player(data))
		//return (printf("Error: No player or multiple players found\n"), 0);
		return(0);
	if (!check_walls(data))
		return (printf("Error: Map is not closed by walls\n"), 0);
	if (!check_spaces(data))
		return (printf("Error: Invalid space configuration\n"), 0);
	if (!check_player_not_trapped(data))
		return (0);
	if (!check_path(data))
		return (printf("Error: Player area is not properly enclosed\n"), 0);
	if (!check_files(&data->config))
		return (printf("Error: Texture files not found\n"), 0);
	return (1);
}
