/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:46 by mokon             #+#    #+#             */
/*   Updated: 2025/05/07 19:41:51 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**copy_of_map;

	game.stars = 0;
	game.moves = 0;
	if (argc != 2)
	{
		printf("Error: No map\n");
		return (1);
	}
	game.map = read_map(argv[1], &game);
	if(game.stars < 1)
	{
		printf("Error: The map has too few stars.\n");
		return (1);
	}
	find_player(&game);
	copy_of_map = copy_map(game.map, game.height);
	flood_fill(copy_of_map, game.player_x, game.player_y, game.width, game.height);
	map_verification(copy_of_map);
	if (!game.map)
	{
		printf("Error: failed to load map\n");
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32,
			"so_long");
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
