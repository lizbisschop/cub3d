# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: liz <liz@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/21 17:37:27 by liz           #+#    #+#                  #
#    Updated: 2020/06/05 15:43:56 by lbisscho      ########   odam.nl          #
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

OBJ = $(SRC:.c=.o)
CFLAGS = -g
LIBFT = ./libft
MLX = ./mlx
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	# @make -C $(LIBFT)
	# @make -C $(MLX)
	# @cp ./mlx/libmlx.dylib ./libmlx.dylib
	# @cp ./libft/libft.a ./libft.a
	@$(CC) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit  \
	$(OBJ) libft.a -o $(NAME)
%.o: %.c
	@printf "Compiling $?\n"
	@gcc $(CFLAGS) -I ./mlx -I ./libft -c $? -o $@
clean:
	@$(RM) $(OBJ)
	@$(RM) $(B_OBJ)
	@$(RM) bonus
	# @make clean -C $(LIBFT)
	# @make clean -C $(MLX)
fclean: clean
	@$(RM) $(BMP)
	@$(RM) $(NAME)
	# @$(RM) libmlx.dylib
	# @$(RM) libft.a
	@make fclean -C $(LIBFT)
re: fclean all
