/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:45:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/11 10:51:37 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	int	i;
	int	has_map_chars;

	if (!line)
		return (0);
	i = 0;
	has_map_chars = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			has_map_chars = 1;
		}
		i++;
	}
	return (has_map_chars);
}

static char	**allocate_new_map(t_data *data, char *trimmed_line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (data->map_height + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[data->map_height] = trimmed_line;
	new_map[data->map_height + 1] = NULL;
	return (new_map);
}

static void	update_map_dimensions(t_data *data, char *trimmed_line)
{
	if ((int)ft_str_len(trimmed_line) > data->map_width)
		data->map_width = ft_str_len(trimmed_line);
	data->map_height++;
}

void	add_map_line(t_data *data, char *line)
{
	char	**new_map;
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, "\t\n");
	if (!trimmed_line)
		return ;
	new_map = allocate_new_map(data, trimmed_line);
	if (!new_map)
	{
		free(trimmed_line);
		return ;
	}
	if (data->map)
		free(data->map);
	data->map = new_map;
	update_map_dimensions(data, trimmed_line);
}

int	check_file_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_str_len(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		printf("Error: Map should be in a .cub extension.\n");
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}
