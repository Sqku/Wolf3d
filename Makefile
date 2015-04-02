NAME	= wolf3d
SRC		= main.c \
		  hook.c \
		  map.c  \
		  draw.c \
		  raycasting.c \
		  keys.c


OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I minilibx_macos

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(OBJ) -o $(NAME) -L libft/ -lft $(FLAGS) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) -I . -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
