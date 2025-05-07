/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:11:04 by mokon             #+#    #+#             */
/*   Updated: 2025/05/07 20:24:48 by mokon            ###   ########.fr       */
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

void	flood_fill(char **map, int player_x, int player_y, int width,
		int height)
{
	if (player_x < 0 || player_y < 0 || player_x >= width || player_y >= height)
		return ;
	if (map[player_y][player_x] == '1' || map[player_y][player_x] == 'X')
		return ;
	if (map[player_y][player_x] == '0' || map[player_y][player_x] == 'C'
		|| map[player_y][player_x] == 'E' || map[player_y][player_x] == 'P')
		map[player_y][player_x] = 'X';
	flood_fill(map, player_x, player_y + 1, width, height);
	flood_fill(map, player_x, player_y - 1, width, height);
	flood_fill(map, player_x + 1, player_y, width, height);
	flood_fill(map, player_x - 1, player_y, width, height);
}

int	map_verification(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				printf("Error: map is not playable\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int border_checker(char **map, int width)
{	
	int flag;
	flag = 0;
	int i;
	i = 0;
	int j;
	j = 0;
	while(map[i])
	{
		if (map[0][i] != '1')
		{
			printf("Error: map is not surrounded by walls.\n");
			exit(1);
		}
	}
}