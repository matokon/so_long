#include "so_long.h"
#include "get_next_line.h"

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


int	count_lines(char *filename)
{
	int fd;
	int count;
	count = 0;
	char *line;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))

	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char **read_map(char *filename, t_game *game)
{
    int fd;
    char **map;
    char *line;
    int i;
    int j;

    i = 0;
    game->stars = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    
    game->height = count_lines(filename);
    if (game->height <= 0)
        return (NULL);

    map = malloc(sizeof(char *) * (game->height + 1));
    if (!map)
        return (NULL);

    while (i < game->height)
    {
        line = get_next_line(fd);
        if (!line)
            break;

        map[i] = line;

        if (i == 0)
        {
            char *newline = ft_strchr(line, '\n');
            if (newline)
                game->width = newline - line;
            else
                game->width = ft_strlen(line);
        }

        j = 0;
        while (j < game->width)
        {
            if (line[j] == 'C')
                game->stars++;
            j++;
        }

        i++;   
    }

    map[i] = NULL;
    close(fd);
    return (map);
}
