NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ignl -g

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = main.c player_movement.c map.c errors.c errors2.c exits.c map_utils.c map_utils2.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c gnl/get_next_line_utils2.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
