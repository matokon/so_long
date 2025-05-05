#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_game
{
    char **map;
    int width;
    int height;
}   t_game;

int	count_lines(char *filename);
char **read_map(char *filename, t_game *game);

#endif