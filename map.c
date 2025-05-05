#include "so_long.h"

void	load_images(t_game *game)
{
	int w;
	int h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	game->img_star = mlx_xpm_file_to_image(game->mlx, "textures/star.xpm", &w, &h);
}

void	render_map(t_game *game)
{
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			char tile = game->map[y][x];
			void *img;

			if (tile == '1')
				img = game->img_wall;
			else if (tile == '0')
				img = game->img_floor;
			else if (tile == 'P')
				img = game->img_player;
			else if (tile == 'E')
				img = game->img_exit;
			else if (tile == 'C')
				img = game->img_star;
			else
				continue;

			mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
		}
	}
}
