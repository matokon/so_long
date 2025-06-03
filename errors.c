/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:11:04 by mokon             #+#    #+#             */
/*   Updated: 2025/06/03 10:45:22 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **og_map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (height > i)
	{
		copy[i] = ft_strdup(og_map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, t_game game, int player_x, int player_y)
{
	int	width;
	int	height;

	width = game.width;
	height = game.height;
	if (player_x < 0 || player_y < 0 || player_x >= width || player_y >= height)
		return ;
	if (map[player_y][player_x] == '1' || map[player_y][player_x] == 'X'
		|| map[player_y][player_x] == 'E')
		return ;
	map[player_y][player_x] = 'X';
	flood_fill(map, game, player_x, player_y + 1);
	flood_fill(map, game, player_x, player_y - 1);
	flood_fill(map, game, player_x + 1, player_y);
	flood_fill(map, game, player_x - 1, player_y);
}

int	border_checker(char **map, t_game game)
{
	int	h;
	int	len;

	h = 0;
	while (h < game.height - 1)
	{
		len = ft_strlen(map[h]);
		if (map[h][0] != '1' || map[h][game.width - 1] != '1' || len
			- 1 != game.width)
			return (1);
		h++;
	}
	h = 0;
	while (map[0][h] < game.width)
	{
		if (map[0][h] != '1' || map[game.height - 1][h] != '1')
			return (1);
		h++;
	}
	if (border_lower_helper(map, game))
		return (1);
	return (0);
}

int	border_lower_helper(char **map, t_game game)
{
	int	h;
	int	i;

	h = game.height - 1;
	i = 0;
	while (map[h][i])
	{
		if (map[h][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
