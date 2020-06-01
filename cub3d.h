/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:12 by liz           #+#    #+#                 */
/*   Updated: 2020/05/29 14:23:13 by liz           ########   odam.nl         */
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
#define ROTATE_RIGHT 65363
#define ROTATE_LEFT 65361

typedef struct s_sprite {
	double 	x;
	double 	y;
	int 	texture;
	int  	first;
	int second;

}				t_sprite;


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
	// char 	array_map_char[100][100];
	int 	**array_map_int;
	int 	floor_color;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char *sprite;
	int valid_map;
	int 	color;

}				t_map;


typedef struct 	s_color {

	int		r;
	int		g;
	int 	b;
}				t_color;

typedef struct  s_tex {
	double 	wall_x;
	int 	tex_x;
	int 	tex_y;
	double 	step;
	double 	tex_pos;
	int 	x;
	int 	y;
	int 	xocolor;
	int 	tex_num;
	int 	xycolor;
}               t_tex;

typedef struct s_textures {
	void  *tex;
	int *texture_adrr;

	int     line_length;
	int     bits_per_pixel;
	int 	tex_width;
	int 	tex_height;
	int     endian;
	

} 				t_textures;

typedef struct 	s_raycasting {
	double pos_x;
	double pos_y;
	double add;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double camera_x;
	double ray_dir_x;
	double ray_dir_y;
	int x_ray;
	int 	map_x;
	int 	map_y;
	double side_dist_x;
	double side_dist_y;
	int step_x;
	int step_y;
	int hit;
	int side;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	int line_height;
	int draw_start;
	int draw_end;
	double frame_time;
	double move_speed;
	double rot_speed;
	int color_ray;
	double old_dir_x;
	double old_dir_y;
	double old_plane_x;
	double old_plane_y;
	char 	type;

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
	t_move	move;
	t_textures textures[5];
	t_tex tex;
	t_sprite *sprite;
	int 	map_width;
	int 	map_height;
	int x;
	int y;
	int		width;
	int 	height;
	int		str_cnt;
	char *file;
	int 			num_sprite;
	unsigned int **buffer;
	double 		*zbuffer;
	int 		*sprite_order;
	double 		*sprite_distance;
	double 		sprite_x;
	double 		sprite_y;
	double 		inv_det;
	double 		transform_x;
	double 		transform_y;
	int 		sprite_screen_x;
	int 		sprite_height;
	int 		sprite_width;
	int 		draw_start_y;
	int 		draw_end_y;
	int 		draw_start_x;
	int 		draw_end_x;
}           t_data;


int		set_struct(t_data *data);
int             close_window(int keycode, t_data *data);
int 	mouse_movement(int x_pos, int y_pos, t_data *data);
int 		mouse_enter(t_data *data);
int 		mouse_leave(t_data *data);
int 	red_cross(int button, t_data *data);
int		print_circle(int x, int y, int r, t_data *data);
int 	print_rectangle(int xw, int yw, int height, int width, unsigned int col, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		hooks(t_data *data);
int		create_trgb(int r, int g, int b);
int		save_map_in_array(t_data *data, char **argv);
void	print_textures(t_data *data);
void	print_map(t_data *data);
int 	background(t_data *data, int col);

int 	save_textures(t_data *data);
int		map_int_array(t_data *data);
int	make_int_array(t_data *data);
void valid_map_check(int x, int y, t_data *data);
void change_map_back(int x, int y, t_data *data);

//LIBFT FILES
int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putstr(char *str);
int 	cubed_strchr(char *str, char c);


//CUB3D FUNCTIONS NEW
int 	get_all_data(t_data *data, char **argv);
int 	setting_mlx(t_data *data);
int		setting_mlx_2(t_data *data);
int textures(t_data *data, char *line, char **relative_path);
int setting_raycasting(t_data *data);
void	exit_program_please(t_data *data, char *str);
int 	raycasting(t_data *data);
int 	draw_line(int drawStart, int drawEnd, int color, t_data *data);
int 	key_input(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		main_loop(t_data *data);
int 	raycasting_loop(t_data *data);
double	ft_abs(double i);
int 	check_type(t_data *data);
int 	textures_make(t_data *data);
int 	draw_buffer(unsigned int **buffer, int x, int y, t_data *data);
unsigned int    add_shade(double distance, unsigned int color);
int which_texture(t_data *data);
void		bubble_sort(t_data *data);
			int 	sprites(t_data *data);
int is_sprite_visible(t_data *data, int color, int i);
void		swap(t_data *data, int j);
int 	loop_through_sprites(t_data *data, int i);
int search_color_sprite(t_data *data, int stripe);
int 	set_sprite_info(t_data *data, int i);
int 	draw_textures(t_data *data);
int		draw_textures_2(t_data *data);
int 	check_right(t_data *data, int keycode);
int 	check_left(t_data *data, int keycode);
int 	check_w(t_data *data, int keycode);
int 	check_s(t_data *data, int keycode);
int 	check_a(t_data *data, int keycode);
int check_d(t_data *data, int keycode);
int		check_type_2(t_data *data);
int save_map(t_data *data, char *line);

#endif