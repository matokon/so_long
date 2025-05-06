#include "get_next_line.h"
#include "so_long.h"

void find_player(t_game *game)
{
    for(int y = 0; game->map[y]; y++)
    {
        for(int x = 0; game->map[y][x]; x++)
        {
            if(game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return ;
            }
        }
    }
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    char next_possition = game->map[new_y][new_x];
    
    if(next_possition == '1')
        return;

    if(next_possition == 'C')
        game->stars--;

    if (next_possition == 'E')
    {
        if (game->stars == 0)
        {
            printf("You won!\n");
            exit(0);
        }
        else
            return;
    }

    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves++;
    printf("Moves: %d\n", game->moves);
    render_map(game);
}

int key_hook(int keycode, t_game *game)
{
    if(keycode == 65307)
        exit(0);
    else if(keycode == 119)
        move_player(game, 0, -1);

    else if(keycode == 97)
        move_player(game, -1, 0);

    else if(keycode == 115)
        move_player(game, 0, 1);
    
    else if(keycode == 100)
        move_player(game, 1, 0);
    return 0;
}
