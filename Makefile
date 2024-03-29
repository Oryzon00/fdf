SRC =	src/main.c \
		src/parsing.c \
		src/free_all.c \
		src/window.c \
		src/utils.c \
		src/hook.c \
		src/print_map.c \
		src/print_line.c \
		src/hook_utils.c \
		src/hook_utils2.c \
		src/hook_utils3.c \
		src/get_scale.c \
		src/color.c \
		src/coor.c

OBJ = $(SRC:.c=.o)

CC = clang

RM = rm -f

DEBUG = -g3

CFLAGS = -Wall -Wextra -Werror -g

OPTI = -O3 -flto

NAME = fdf

PATH_MLX =./mlx

PATH_LIBFT = ./libft

LINUX    = -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

MLX = ./mlx/libmlx.a

%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux  -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			make -C $(PATH_MLX) all --silent
			make -C $(PATH_LIBFT) bonus --silent
			$(CC)  $(CFLAGS) $(OBJ) mlx/libmlx_Linux.a libft/libft.a $(LINUX) -o $(NAME)

clean:
		rm -f $(OBJ)
		make -C $(PATH_LIBFT) fclean --silent
		make -C $(PATH_MLX) clean --silent

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re 
