/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:45:37 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/16 10:58:57 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int process_line(char *line, t_data *data)
{
   if (is_texture_line(line))
   {
       //printf("Texture trouvée: %s", line);
       if (!parse_texture_line(line, &data->config))
           return (0);
       return (1);
   }
   else if (is_color_line(line))
   {
       //printf("Couleur trouvée: %s", line);
       if (!parse_color_line(line, &data->config))
           return (0);
       return (1);
   }
   else if (is_map_line(line))
   {
       //printf("Ligne de carte trouvée: %s", line);
       if (!validate_order(data))
           return (0);
       
       add_map_line(data, line);
       return (1);
   }
   else
   {
       printf("Ligne ignorée : %s", line);
       return (0);
   }
}

int	parse_file(const char *filename, t_data *data)
{
	int		fd;
	int		line_number;
	char	*line;

	line_number = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: ouverture fichier\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			//printf("Ligne %d:\n", line_number);
			if (!process_line(line, data))
			{
				free(line);
				close(fd);
				get_next_line(-1);
				return (1);
			}
		}
		line_number++;
		free(line);
	}
	close(fd);
	get_next_line(-1);
	return (0);
}

int validate_order(t_data *data)
{
    if (!data->config.texture_north || !data->config.texture_south || 
        !data->config.texture_west || !data->config.texture_est)
    {
        printf("Error: Missing textures before map\n");
        return (0);
    }
    if (data->config.floor_color == -1 || data->config.ceiling_color == -1)
    {
        printf("Error: Missing colors before map\n");
        return (0);
    }
    return (1);
}
