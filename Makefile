NAME = so_long

SRC = src/parsing.c src/render.c src/parsing2.c src/pathfind.c src/init.c src/hook_handle.c src/error.c src/main.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -I./libft -I./minilibx-linux -g

LIBFT = ./libft/libft.a

LIBMLX = ./minilibx-linux/libmlx_Linux.a

all : $(NAME)

$(NAME) : libft lib_mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LIBMLX) -lX11 -lXext -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

libft :
	@make -C ./libft

lib_mlx : 
	@make -C ./minilibx-linux

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all

.PHONY: all, clean, fclean, re, libft
