NAME = so_long

BONUS_NAME = so_long_b

SRC = src/parsing.c src/render.c src/parsing2.c src/pathfind.c src/init.c src/hook_handle.c src/error.c src/main.c

OBJ = $(SRC:.c=.o)

SRC_B = src_b/parsing.c src_b/render.c src_b/parsing2.c src_b/pathfind.c src_b/init.c src_b/hook_handle.c src_b/error.c src_b/main.c

OBJ_B = $(SRC_B:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -I./libft -I./minilibx-linux -g

LIBFT = ./libft/libft.a

LIBMLX = ./minilibx-linux/libmlx_Linux.a

all : libft lib_mlx $(NAME)

bonus : libft lib_mlx $(BONUS_NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(LIBMLX) -lX11 -lXext -o $(NAME)

$(BONUS_NAME) : $(OBJ_B)
	@$(CC) $(OBJ_B) $(LIBFT) $(LIBMLX) -lX11 -lXext -o $(BONUS_NAME)

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

libft :
	@make -C ./libft

lib_mlx : 
	@make -C ./minilibx-linux

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@make fclean -C ./libft

re : fclean all

re_b : fclean bonus

.PHONY: all clean fclean re libft bonus re_b