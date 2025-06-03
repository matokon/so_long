/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:06:20 by mokon             #+#    #+#             */
/*   Updated: 2025/06/03 12:09:06 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
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
char		**read_map_lines(int fd, t_game *game, char **map);
char		**allocate_and_open_map(char *filename, t_game *game, int *fd);
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
int			print_error_and_exit(t_game *game, char *message,
				int len);
int			print_no_map_error(char *message, int len);
void		move_player_helper(t_game *game, int new_x, int new_y);
void		*get_image_for_tile(char tile, t_game *game);
char		**allocate_map(char *filename, t_game *game);
void		set_map_width(char *line, t_game *game);
void		process_map_line(char *line, t_game *game);
void		free_map(char **map);
char		**write_error(char *msg, size_t len, char **map);
int			validate_player_and_exit(char **map);
int			validate_map(char **map);
int			check_exit_surroundings(char **map, t_game game);
int			is_exit_accessible(char **map, int i, int j, t_game game);
#endif
