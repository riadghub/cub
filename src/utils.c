/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:46 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/11 11:35:08 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	has_wall_at(t_data *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map_height)
		return (1);
	if (x >= ft_str_len(game->map[y]))
		return (1);
	return (game->map[y][x] == '1');
}