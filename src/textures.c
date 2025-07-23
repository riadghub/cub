#include "cub3d.h"

void *load_texture(void *mlx, char *path)
{
    int width, height;
    void *texture;

    if (!path)
    {
        printf("Error: Texture path is NULL\n");
        exit(1);
    }

    texture = mlx_xpm_file_to_image(mlx, path, &width, &height);
    if (!texture)
    {
        printf("Error: Failed to load texture: %s\n", path);
        printf("Make sure the file exists and is a valid XMP file\n");
        exit(1);
    }

    return (texture);
}

int	load_all_textures(t_data *game)
{
	game->config.wall = load_texture(game->mlx, WALL_PATH);
	game->config.floor = load_texture(game->mlx, FLOOR_PATH);
	game->player.texture_player = load_texture(game->mlx, PLAYER_PATH);
	// game->textures.player_down = load_texture(game->mlx, PLAYER_DOWN_PATH);
	// game->textures.player_left = load_texture(game->mlx, PLAYER_LEFT_PATH);
	// game->textures.player_right = load_texture(game->mlx, PLAYER_RIGHT_PATH);
	// game->textures.player_up = load_texture(game->mlx, PLAYER_UP_PATH);
	// game->textures.collectible = load_texture(game->mlx, CHEST_PATH);
	// game->textures.exit = load_texture(game->mlx, EXIT_PATH);
	// if (!game->textures.collectible || !game->textures.wall
	// 	|| !game->textures.player || !game->textures.player_down
	// 	|| !game->textures.player_left || !game->textures.player_right
	// 	|| !game->textures.player_up || !game->textures.exit
	// 	|| !game->textures.floor)
	// {
	// 	ft_printf("Error: Failed to load texture.\n");
	// 	return (0);
	// }
	return (1);
}

void	free_textures(t_data *game)
{
	if (game->config.wall)
		mlx_destroy_image(game->mlx, game->config.wall);
	if (game->player.texture_player)
		mlx_destroy_image(game->mlx, game->player.texture_player);
	// if (game->textures.player_down)
	// 	mlx_destroy_image(game->mlx, game->textures.player_down);
	// if (game->textures.player_left)
	// 	mlx_destroy_image(game->mlx, game->textures.player_left);
	// if (game->textures.player_right)
	// 	mlx_destroy_image(game->mlx, game->textures.player_right);
	// if (game->textures.player_up)
	// 	mlx_destroy_image(game->mlx, game->textures.player_up);
	// if (game->textures.collectible)
	// 	mlx_destroy_image(game->mlx, game->textures.collectible);
	// if (game->textures.exit)
	// 	mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->config.floor)
		mlx_destroy_image(game->mlx, game->config.floor);
}