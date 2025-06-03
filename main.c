/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:46 by mokon             #+#    #+#             */
/*   Updated: 2025/06/03 12:09:03 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_and_validate(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		return (print_no_map_error("Error\n: No map", 15));
	ft_bzero(game, sizeof(t_game));
	game->map = read_map(argv[1], game);
	if (!game->map)
		return (print_error_and_exit(game,
				"Error\n: failed to load map", 27));
	if (game->stars < 1)
		return (print_error_and_exit(game,
				"Error\n: The map has too few stars.", 35));
	find_player(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**copy;

	if (init_and_validate(&game, argc, argv))
		return (1);
	copy = copy_map(game.map, game.height);
	if (validate_map(copy))
		return (free_map(copy), close_window(&game), 1);
	if (validate_player_and_exit(copy))
		return (free_map(copy), close_window(&game), 1);
	flood_fill(copy, game, game.player_x, game.player_y);
	map_verification(copy, game);
	free_map(copy);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32,
			"so_long");
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
