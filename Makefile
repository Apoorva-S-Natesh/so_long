NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
PRINTF = ./printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/check_content_wall.c src/check_route_rect.c \
		src/drawmap.c src/hooks_closes.c src/check_collect_win.c\
		src/move_right_left.c src/move_up_down.c\
		
BONUS_SRC = bonus/so_long_bonus.c bonus/check_content_wall.c bonus/check_route_rect.c \
		bonus/drawmap.c bonus/hooks_closes.c bonus/check_collect_win.c\
		bonus/move_right_left.c bonus/move_up_down.c bonus/ft_enemy_move.c\
		bonus/draw_move_window.c\

UTIL_SRC = 	utils/ft_strdup.c utils/get_next_line.c utils/get_next_line_utils.c \
		utils/ft_strncmp.c utils/ft_itoa.c utils/ft_strcpy.c

INCLUDE = -I/usr/include -Imlx_linux

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

HEAD = so_long.h

HEAD_BONUS = so_long_bonus.h

SRC_OBJ = $(SRC:.c=.o) 
BONUS_OBJ = $(BONUS_SRC:.c=.o)
UTIL_OBJ = $(UTIL_SRC:.c=.o)

all: $(NAME)
bonus: $(BONUS_NAME)

$(SRC_OBJ): %.o: %.c $(HEAD)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_OBJ): %.o: %.c $(HEAD_BONUS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(UTIL_OBJ): %.o: %.c $(HEAD)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(SRC_OBJ) $(PRINTF) $(HEAD) $(UTIL_OBJ)
	@$(CC) $(FLAGS) $(SRC_OBJ) $(UTIL_OBJ) $(MLX_FLAGS) $(PRINTF) -o $(NAME)
	@echo "Built $(NAME)"

$(BONUS_NAME): $(BONUS_OBJ) $(PRINTF) $(HEAD_BONUS) $(UTIL_OBJ)
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(UTIL_OBJ) $(MLX_FLAGS) $(PRINTF) -o $(BONUS_NAME)
	@echo "Built $(BONUS_NAME)"

$(PRINTF):
	@$(MAKE) -C ./printf -f Makefile all
	@$(MAKE) -C ./printf -f Makefile clean

clean:
	@rm -rf $(SRC_OBJ) $(BONUS_OBJ) $(UTIL_OBJ)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf printf/libftprintf.a
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "Fully cleaned project"

re: fclean all

.PHONY: all clean fclean re bonus
