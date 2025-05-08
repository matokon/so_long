/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:06:00 by mokon             #+#    #+#             */
/*   Updated: 2025/05/08 19:48:45 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w,
			&h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w,
			&h);
	game->img_star = mlx_xpm_file_to_image(game->mlx, "textures/star.xpm", &w,
			&h);
}

void	*get_image_for_tile(char tile, t_game *game)
{
	if (tile == '1')
		return (game->img_wall);
	else if (tile == '0')
		return (game->img_floor);
	else if (tile == 'P')
		return (game->img_player);
	else if (tile == 'E')
		return (game->img_exit);
	else if (tile == 'C')
		return (game->img_star);
	return (NULL);
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;
	void	*img;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			img = get_image_for_tile(tile, game);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y
					* 32);
			x++;
		}
		y++;
	}
}

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
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

char	**read_map(char *filename, t_game *game)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		j;
	char	*newline;

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
			break ;
		map[i] = line;
		if (i == 0)
		{
			newline = ft_strchr(line, '\n');
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
