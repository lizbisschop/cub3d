# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <liz@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz           #+#    #+#                  #
#    Updated: 2020/05/05 12:54:48 by liz           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFLIBFT = libft.a

SRC = cub3d_real.c ./srcs/print_textures.c \
./srcs/hooks.c ./srcs/shapes.c \
./srcs/read_map.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
./srcs/valid_map_check.c get_all_data.c img_filling.c exit.c \
raycasting.c ./keys.c ./main_loop.c functions.c \
textures.c

LIBLIBFT = libft.a

OBJ = $(SRC:.c=.o)

INC = cub3d.h ./gnl/get_next_line.h ./libft/libft.h ./mlx/mlx.h ./libft/libft.h

MLX = libmlx.a

all: $(NAME)

$(NAME):$(MLX) $(OBJ) $(LIBLIBFT)
		gcc -o $(NAME) $(INC) $(OBJ) libft.a $(MLX) -lm -lX11 -lXext -g

# $(MLX):
# 		@make -C ./mlx
# 		@cp mlx/$(MLX) .
# $(LIBLIBFT):
# 		@make -C ./libft
# 		@cp libft/$(LIBLIBFT) .

clean:
		@make -C ./libft clean
		@make -C ./mlx clean
		rm -f $(OBJ)

fclean:	clean
		# rm -f $(LIBLIBFT)
		rm -f $(NAME)
		# rm -f $(MLX)

re:		fclean all
