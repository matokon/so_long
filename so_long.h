/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:06:20 by mokon             #+#    #+#             */
/*   Updated: 2025/05/08 19:12:05 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_star;

	int		player_x;
	int		player_y;

	int		stars;
	int		moves;

}			t_game;

int			count_lines(char *filename);
char		**read_map(char *filename, t_game *game);
void		load_images(t_game *game);
void		render_map(t_game *game);
void		find_player(t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			key_hook(int keycode, t_game *game);
char		**copy_map(char **og_map, int height);
void		flood_fill(char **map, t_game game, int player_x, int player_y);
int			map_verification(char **map, t_game game);
int			border_checker(char **map, t_game game);
int			close_window(t_game *game);
int			border_lower_helper(char **map, t_game game);
int			print_error_and_exit(char *message);
void		move_player_helper(t_game *game, int new_x, int new_y);
void	*get_image_for_tile(char tile, t_game *game);
#endif
