/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:06:10 by mokon             #+#    #+#             */
/*   Updated: 2025/05/09 11:56:16 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_possition;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next_possition = game->map[new_y][new_x];
	if (next_possition == '1')
		return ;
	if (next_possition == 'C')
		game->stars--;
	if (next_possition == 'E')
	{
		if (game->stars == 0)
		{
			write(1, "Moves: ", 7);
			ft_putnbr(game->moves + 1);
			write(1, "\nYou won!\n", 9);
			close_window(game);
			exit(0);
		}
		else
			return ;
	}
	move_player_helper(game, new_x, new_y);
}

void	move_player_helper(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	render_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
