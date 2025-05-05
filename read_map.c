#include "get_next_line.h"
#include "so_long.h"

int	count_lines(char *filename)
{
	int fd;
	int count;
	count = 0;
	char *line;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))

	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char **read_map(char *filename, t_game *game)
{
    int fd;
    char **map;
    char *line;
    int i;
    i = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    
    game->height = count_lines(filename);
    if(game->height <= 0)
        return(NULL);
    map = malloc(sizeof(char *) * (game->height + 1));
    if (!map)
        return (NULL);

    while(i < game->height)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        map[i] = line;
        if (i == 0)
        {
	        char *newline = ft_strchr(line, '\n');
	        if (newline)
		        game->width = newline - line;
	        else
		        game->width = ft_strlen(line);
        }
        i++;   
    }
    map[i] = NULL;
    close(fd);
    return(map);
}