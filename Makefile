NAME = so_long
CC = cc
PRINTF = ./printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/check_content_wall.c src/check_route_rect.c \
		src/drawmap.c src/hooks_closes.c src/check_collect_win.c\
		src/move_right_left.c src/move_up_down.c\
		utils/ft_strdup.c utils/get_next_line.c utils/get_next_line_utils.c \
		utils/ft_strncmp.c utils/ft_itoa.c \
		
INCLUDE = -I/usr/include -Imlx_linux

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

HEAD = so_long.h

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEAD) 
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(PRINTF) $(HEAD)
	ar rc $(NAME) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) $(PRINTF) -o $(NAME) 

$(PRINTF):
	$(MAKE) -C ./printf -f Makefile all
	$(MAKE) -C ./printf -f Makefile clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf printf/libftprintf.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
