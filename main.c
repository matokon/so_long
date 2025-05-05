#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

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
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32, "so_long");

    load_images(&game);
    render_map(&game);
    mlx_loop(game.mlx);
    
    return 0;
}