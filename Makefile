# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <liz@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz           #+#    #+#                  #
#    Updated: 2020/06/02 13:55:48 by liz           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFLIBFT = libft.a

SRC = cub3d_real.c ./srcs/color.c\
./srcs/read_map.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
./srcs/valid_map_check.c ./srcs/get_all_data.c ./srcs/img_filling.c ./srcs/exit.c \
./srcs/raycasting.c ./srcs/keys.c ./srcs/main_loop.c ./srcs/make_array_map.c \
./srcs/textures.c ./srcs/sprites.c ./srcs/bubble_sort.c ./srcs/keys_2.c ./srcs/check_type.c \
./srcs/find_width_height.c ./srcs/find_textures.c ./srcs/find_color.c \

LIBLIBFT = libft.a

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

INC = cub3d.h ./gnl/get_next_line.h ./libft/libft.h ./mlx/mlx.h ./libft/libft.h

MLX = libmlx.a

all: $(NAME)

$(NAME):$(MLX) $(OBJ) $(LIBLIBFT)
		gcc $(FLAGS) -o $(NAME) $(INC) $(OBJ) libft.a $(MLX) -lm -lX11 -lXext -g

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
