/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:07:35 by mokon             #+#    #+#             */
/*   Updated: 2025/05/08 20:57:35 by mokon            ###   ########.fr       */
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
