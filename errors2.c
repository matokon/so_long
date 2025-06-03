/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:42:56 by mokon             #+#    #+#             */
/*   Updated: 2025/06/03 12:09:08 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verification(char **map, t_game game)
{
	if (!check_exit_surroundings(map, game) || border_checker(map, game))
	{
		write(1, "Error\n: map is not playable\n", 27);
		free_map(map);
		close_window(&game);
		exit(1);
	}
	return (1);
}

int	is_exit_accessible(char **map, int i, int j, t_game game)
{
	if ((i + 1 < game.height && map[i + 1][j] == 'X') || (i - 1 >= 0 && map[i
			- 1][j] == 'X') || (j + 1 < game.width && map[i][j + 1] == 'X')
		|| (j - 1 >= 0 && map[i][j - 1] == 'X'))
		return (1);
	return (0);
}

int	check_exit_surroundings(char **map, t_game game)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			if (map[i][j] == 'E' && is_exit_accessible(map, i, j, game))
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}
