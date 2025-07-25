/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:45:42 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/22 11:42:11 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
}

static int	count_players(t_data *data, int *player_x, int *player_y,
		char *player_direction)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				count++;
				if (count == 1)
				{
					*player_x = x;
					*player_y = y;
					*player_direction = data->map[y][x];
				}
			}
			x++;
		}
		y++;
	}
	return (count);
}

int find_player(t_data *data)
{
    int count;
    int player_x;
    int player_y;
    char player_direction;
    
    count = count_players(data, &player_x, &player_y, &player_direction);
    
    if (count == 0)
        return (printf("Error: No player found in map (N, S, E, or W required)\n"), 0);
    else if (count > 1)
        return (printf("Error: Multiple players found (%d players). Only one allowed\n", count), 0);
    data->player.pos[0] = player_x;        // X → pos[0]
    data->player.pos[1] = player_y;        // Y → pos[1]
    data->player.direction = player_direction;
    data->map[player_y][player_x] = '0';
    return (1);
}

int	check_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
				&& data->map[i][j] != ' ')
			{
				printf("Error: ");
				printf("Invalid character '%c' at line %d, column %d\n",
					data->map[i][j], i + 1, j + 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
