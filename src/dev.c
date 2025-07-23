#include "cub3d.h"

// void	print_texture(char *name, char *texture)
// {
// 	printf("Texture %s: ", name);
// 	if (texture)
// 		printf("%s\n", texture);
// 	else
// 		printf("Non définie\n");
// }

// void	print_textures(t_config *config)
// {
// 	print_texture("Nord", config->texture_north);
// 	print_texture("Sud", config->texture_south);
// 	print_texture("Ouest", config->texture_west);
// 	print_texture("Est", config->texture_est);
// }

// void	print_config(t_config *config)
// {
// 	printf("=== CONFIGURATION ===\n");
// 	print_textures(config);
// 	printf("Couleur sol: %d\n", config->floor_color);
// 	printf("Couleur plafond: %d\n", config->ceiling_color);
// 	printf("=====================\n");
// }

// void	print_map(t_data *data)
// {
// 	int	i;

// 	printf("=== CARTE ===\n");
// 	printf("Dimensions: %d x %d\n", data->map_width, data->map_height);
// 	printf("Joueur: (%f, %f) direction '%c'\n", data->player.x, data->player.y,
// 		data->player.direction);
// 	if (!data->map)
// 	{
// 		printf("ERREUR: data->map est NULL!\n");
// 		return ;
// 	}
// 	i = 0;
// 	while (i < data->map_height)
// 	{
// 		printf("[%d] %s\n", i, data->map[i]);
// 		i++;
// 	}
// 	printf("============\n");
// }