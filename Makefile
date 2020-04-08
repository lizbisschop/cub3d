# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <liz@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz           #+#    #+#                  #
#    Updated: 2020/04/08 13:57:15 by liz           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFLIBFT = libft.a

SRC = cub3d_try.c ./srcs/print_textures.c ./srcs/print_map.c ./srcs/libft_files.c ./srcs/hooks.c ./srcs/shapes.c ./srcs/read_map.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INC = cub3d.h ./gnl/get_next_line.h ./libft/libft.h ./mlx/mlx.h ./libft/libft.h

MLX = libmlx.a

all: $(NAME)

$(NAME):$(MLX) $(OBJ) $(LILIBFT)
		gcc -o $(NAME) $(INC) $(OBJ) $(MLX) libft.a -lm -lX11 -lXext -g

$(MLX):
		@make -C ./mlx
		@cp mlx/$(MLX) .
$(LIBLIBFT):
		@make -C ./libft
		@cp libft/$(LIBLIBFT) .

clean:
		@make -C ./libft clean
		@make -C ./mlx clean
		rm -f $(OBJ)

fclean:	clean
		rm -f $(LIBLIBFT)
		rm -f $(NAME)
		rm -f $(MLX)

re:		fclean all
