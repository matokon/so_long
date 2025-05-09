/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:07:35 by mokon             #+#    #+#             */
/*   Updated: 2025/05/09 13:27:53 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	set_map_width(char *line, t_game *game)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (newline)
		game->width = newline - line;
	else
		game->width = ft_strlen(line);
}

void	process_map_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while (j < game->width)
	{
		if (line[j] == 'C')
			game->stars++;
		j++;
	}
}

int	validate_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'P' && map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != '\n')
			{
				write(1, "Error\nInvalid character", 23);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_player_and_exit(char **map)
{
	int	p_count;
	int	e_count;
	int	y;
	int	x;

	p_count = 0;
	e_count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				p_count++;
			if (map[y][x] == 'E')
				e_count++;
		}
	}
	if (p_count != 1 || e_count != 1)
	{
		write(1, "Error\nMap must contain exactly 1 P and 1 E\n", 42);
		return (1);
	}
	return (0);
}
