#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }
    game.map = read_map(argv[1], &game);
    if (!game.map)
    {
        printf("Error: failed to load map\n");
        return (1);
    }
    for (int i = 0; game.map[i]; i++)
        printf("%s", game.map[i]);
    return 0;
}