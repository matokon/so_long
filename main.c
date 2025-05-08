/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:46 by mokon             #+#    #+#             */
/*   Updated: 2025/05/08 18:34:11 by mokon            ###   ########.fr       */
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
		return (print_error_and_exit("Error: No map"));
	game.map = read_map(argv[1], &game);
	if (!game.map)
		return (print_error_and_exit("Error: failed to load map"));
	if (game.stars < 1)
		return (print_error_and_exit("Error: The map has too few stars."));
	find_player(&game);
	copy_of_map = copy_map(game.map, game.height);
	flood_fill(copy_of_map, game, game.player_x, game.player_y);
	map_verification(copy_of_map, game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32,
			game.height * 32, "so_long");
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
