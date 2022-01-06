SRC = src/main.c	\

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = fdf

PATH_MLX =./mlx

PATH_LIBFT = ./libft

LINUX    = -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

%.o: %.c
		$(CC) -I /usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			make -C $(PATH_MLX) all --silent
			make -C $(PATH_LIBFT) bonus --silent
			$(CC) $(OBJ) mlx/libmlx_Linux.a libft/libft.a $(LINUX) -o $(NAME)

clean:
		rm -f $(OBJ)
		make -C $(PATH_LIBFT) fclean --silent
		make -C $(PATH_MLX) clean --silent

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re 
