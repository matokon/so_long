/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:19:06 by mokon             #+#    #+#             */
/*   Updated: 2025/05/09 13:25:04 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_and_open_map(char *filename, t_game *game, int *fd)
{
	char	**map;

	map = allocate_map(filename, game);
	if (!map)
		return (NULL);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		write(1, "Error\nFailed to open map\n", 26);
		return (NULL);
	}
	return (map);
}

char	**read_map_lines(int fd, t_game *game, char **map)
{
	char	*line;
	int		i;

	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = line;
		if (i == 0)
			set_map_width(line, game);
		process_map_line(line, game);
		i++;
	}
	map[i] = NULL;
	return (map);
}
