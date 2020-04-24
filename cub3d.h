/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:12 by liz           #+#    #+#                 */
/*   Updated: 2020/04/23 11:51:13 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "./mlx/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <math.h>


//remove!!!!!
#include <stdio.h>


//KEYS
#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100


typedef struct s_error {
	int check_double;

}				t_error;

typedef struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
	void	*img;
    char    *addr;
    int     bits_per_pixel;
    int     endian;
	int		img_width;
	int		img_height;
	void	*img_ptr;
    int     line_length;
}				t_mlx;

typedef struct 	s_map {
	char	*map;
	char 	array_map_char[100][100];
	int 	array_map_int[100][100];
	int 	floor_color;
	void	*NO_texture;
	void	*SO_texture;
	void	*EA_texture;
	void	*WE_texture;
	void	*sprite;
	int valid_map;
	int 	color;

}				t_map;

typedef struct 	s_color {

	int		r;
	int		g;
	int 	b;
}				t_color;

typedef struct 	s_raycasting {
	double posX;
	double posY;
	double add;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int x_ray;
	int 	mapX;
	int 	mapY;
	double sideDistX;
	double sideDistY;
	int stepX;
	int stepY;
	int hit;
	int side;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int lineHeight;
	int drawStart;
	int drawEnd;
	double frameTime;
	double moveSpeed;
	double rotSpeed;
	int color_ray;
	double oldDirX;
	double oldDirY;
	double oldPlaneX;
	double oldPlaneY;

}				t_raycasting;

typedef struct 	s_move {
	int x;
	int y;

}				t_move;

typedef struct s_data {
	
	t_mlx	mlx;
	t_map	map;
	t_color	color;
	t_raycasting	ray;
	t_error error;
	t_move	move;
	int 	xw;
	int 	yw;
	int x;
	int y;
	int		width;
	int 	height;
	int		str_cnt;
	char *file;
}           t_data;


int		set_struct(t_data *data);
int             close_window(int keycode, t_data *data);
int 	mouse_movement(int x_pos, int y_pos, t_data *data);
int 		mouse_enter(t_data *data);
int 		mouse_leave(t_data *data);
int 	red_cross(int button, t_data *data);
// int 	render_next_frame(t_data *data);
int		print_circle(int x, int y, int r, t_data *data);
int 	print_rectangle(int xw, int yw, int height, int width, unsigned int col, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		hooks(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		save_map_in_array(t_data *data);
void	print_textures(t_data *data);
void	print_map(t_data *data);
// int 	wasd(int keycode, t_data *data);
int 	background(t_data *data, int col);

int 	save_textures(t_data *data);
int		map_int_array(t_data *data);
int	make_char_array(t_data *data);
int	make_int_array(t_data *data);
void valid_map_check(int x, int y, t_data *data);
void change_map_back(int x, int y, t_data *data);

//LIBFT FILES
int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putstr(char *str);


//CUB3D FUNCTIONS NEW
int 	get_all_data(t_data *data);
int 	setting_mlx(t_data *data);
int textures(t_data *data, char *line, char **relative_path);
int setting_raycasting(t_data *data);
void	exit_program_please(t_data *data, char *str);
int 	raycasting(t_data *data);
int 	draw_line(int x, int drawStart, int drawEnd, int color, t_data *data);
int 	key_input(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		main_loop(t_data *data);

#endif