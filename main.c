/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:46 by mokon             #+#    #+#             */
/*   Updated: 2025/05/06 16:46:05 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.stars = 0;
	game.moves = 0;
	if (argc != 2)
	{
		printf("No map\n");
		return (1);
	}
	game.map = read_map(argv[1], &game);
	if (!game.map)
	{
		printf("Error: failed to load map\n");
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32,
			"so_long");
	find_player(&game);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
