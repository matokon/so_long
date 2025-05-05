#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;

    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_exit;
    void    *img_star;

    int     player_x;
    int     player_y;
} t_game;


int	count_lines(char *filename);
char **read_map(char *filename, t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);

#endif