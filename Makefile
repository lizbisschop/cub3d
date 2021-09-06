# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <lizstudent.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz           #+#    #+#                  #
#    Updated: 2020/06/25 17:35:44 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFLIBFT = libft.a

SRC = cub3d.c ./srcs/color.c\
./srcs/read_map.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
./srcs/valid_map_check.c ./srcs/get_all_data.c \
./srcs/img_filling.c ./srcs/exit.c \
./srcs/raycasting.c ./srcs/keys.c ./srcs/main_loop.c ./srcs/make_array_map.c \
./srcs/textures.c ./srcs/sprites.c ./srcs/bubble_sort.c \
./srcs/keys_2.c ./srcs/check_type.c \
./srcs/find_width_height.c ./srcs/find_textures.c \
./srcs/find_color.c ./srcs/bmp.c ./srcs/key_press.c \
./srcs/set_all_to_zero.c ./srcs/make_textures.c ./srcs/check_color.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft

MLX = ./mlx

BMP = bitmap.bmp

all: $(NAME)
$(NAME): $(OBJ) $(SRC)
	make -C $(LIBFT)
	make -C $(MLX)
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	cp ./libft/libft.a ./libft.a
	gcc $(CFLAGS) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit \
	$(OBJ) libft.a -o $(NAME)
%.o: %.c
	gcc $(CFLAGS) -I ./mlx -I libft.a -c $< -o $@
clean:
	rm -rf $(OBJ)
	rm -rf bitmap.bmp
	make clean -C $(LIBFT)
	make clean -C $(MLX)
fclean: clean
	rm -rf $(BMP)
	rm -rf $(NAME)
	rm -rf bitmap.bmp
	rm -rf libmlx.dylib
	rm -rf libft.a
	make fclean -C $(LIBFT)
re: fclean all

.PHONY: all clean fclean re
