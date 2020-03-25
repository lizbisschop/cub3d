# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <liz@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz            #+#    #+#                 #
#    Updated: 2020/03/25 13:07:05 by liz           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = cub3d.c

OBJ = $(SRC:.c=.o)

INC = cub3d.h ./mlx/mlx.h

MLX = libmlx.a

all: $(NAME)

$(NAME):$(MLX) $(OBJ)
		gcc -o $(NAME) cub3d.h ./mlx/mlx.h $(OBJ) libmlx.a -lm -lX11 -lXext -g

$(MLX):
		@make -C ./mlx
		@cp mlx/$(MLX) .

clean:
		@make -C ./mlx clean
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f $(MLX)

re:		fclean all
