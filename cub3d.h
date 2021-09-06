/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:12 by liz           #+#    #+#                 */
/*   Updated: 2020/07/03 11:31:19 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <math.h>
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123

typedef struct		s_sprite {
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_mlx {
	void			*mlx;
	void			*mlx_win;
	void			*img;
	void			*img_2;
	char			*addr;
	int				bits_per_pixel;
	int				endian;
	int				img_width;
	int				img_height;
	void			*img_ptr;
	int				line_length;
}					t_mlx;

typedef struct		s_map {
	char			*map;
	int				**array_map;
	int				floor_color;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*sprite;
	int				valid_map;
	int				color;
	char			*old_line;
}					t_map;

typedef struct		s_color {
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_tex {
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				xocolor;
	int				tex_num;
	int				xycolor;
}					t_tex;

typedef struct		s_textures {
	void			*tex;
	int				*texture_adrr;
	int				line_length;
	int				bits_per_pixel;
	int				tex_width;
	int				tex_height;
	int				endian;
}					t_textures;

typedef struct		s_raycasting {
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				x_ray;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	int				color_ray;
	double			old_dir_x;
	double			old_dir_y;
	double			old_plane_x;
	double			old_plane_y;
	char			type;
}					t_raycasting;

typedef struct		s_move {
	int				w;
	int				s;
	int				d;
	int				a;
	int				l;
	int				r;
}					t_move;

typedef struct		s_sprites {
	int				num_sprite;
	unsigned int	**buffer;
	double			*zbuffer;
	int				*sprite_order;
	double			*sprite_distance;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
}					t_sprites;

typedef struct		s_data {
	t_mlx			mlx;
	t_map			map;
	t_color			colors;
	t_raycasting	ray;
	t_move			move;
	t_textures		textures[7];
	t_tex			tex;
	t_sprite		*sprite;
	t_sprites		sprites;
	int				not_map_string;
	int				chars;
	int				array;
	int				sprites_count;
	int				map_width;
	int				map_height;
	int				width;
	int				height;
	int				str_cnt;
	char			*file;
	int				type_found;
	int				color;
	int				map_started;
	int				map_stopped;
	int				save;
	int				map_start;

}					t_data;

int					close_screen(void);
void				get_all_data(t_data *data, char **argv);
int					main_loop(t_data *data);
int					setting_mlx(t_data *data);
int					setting_mlx_2(t_data *data);
int					create_bmp(t_data *data);
void				while_loop_bmp(t_data *data, int fd, int len);
int					header(t_data *data, int fd);
void				bubble_sort(t_data *data);
void				swap(t_data *data, int j);
int					check_type(t_data *data);
int					check_type_2(t_data *data);
int					create_trgb(int r, int g, int b);
void				exit_program_please(char *str);
void				if_statements_main(t_data *data, char **argv);
void				ft_putstr(char *str);
void				color(t_data *data, char *line);
void				find_floor_color(t_data *data, char *line);
int					check_floor_color(t_data *data, char *line,
					int *i, int check_com_f);
void				find_color(t_data *data, char *line);
int					check_color(t_data *data, char *line,
					int *i, int check_com_c);
int					textures(t_data *data, char *line);
void				we_ea(t_data *data, char *line);
void				no_so(t_data *data, char *line);
int					find_width_height(t_data *data, char *line);
void				find_width_height_2(t_data *data, char *line);
void				floor_casting(t_data *data);
void				while_loop_floor_casting(t_data *data, int y);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);
void				key_input(t_data *data);
void				check_w(t_data *data);
void				check_s(t_data *data);
void				check_right(t_data *data);
void				check_left(t_data *data);
void				check_a(t_data *data);
void				check_d(t_data *data);
int					make_int_array(t_data *data);
int					save_int_array(t_data *data);
int					if_statements_array(t_data *data, int i);
int					save_map_width_height(t_data *data);
int					malloc_array_map(t_data *data);
void				make_texture_sprite(t_data *data);
void				make_texture_we(t_data *data);
void				make_texture_ea(t_data *data);
void				make_texture_so(t_data *data);
void				make_texture_no(t_data *data);
int					raycasting(t_data *data);
int					raycasting_loop(t_data *data);
int					calculating_step(t_data *data);
int					wall_is_hit(t_data *data);
int					what_to_draw(t_data *data);
void				save_map_in_array(t_data *data, char **argv);
void				check_map_line(t_data *data, char *line, char **tmp);
int					map_part_found(t_data *data, char **tmp, char *line);
char				*add_newline(char *str);
void				set_all_to_zero(t_data *data);
void				set_all_to_zero_2(t_data *data);
int					sprites(t_data *data);
void				loop_through_sprites(t_data *data, int i);
void				set_sprite_info(t_data *data, int i);
void				if_statements_sprite(t_data *data);
void				search_color_sprite(t_data *data, int stripe);
int					textures_make(t_data *data);
int					draw_textures(t_data *data);
void				draw_textures_2(t_data *data);
int					which_texture(t_data *data);
void				change_map_back(int x, int y, t_data *data);
void				valid_map_check(int x, int y, t_data *data);
int					ft_strcmp(char *str1, char *str2);
void				loop(t_data *data);
void				check_identifier(t_data *data, char *line);
void				check_ceiling_color(t_data *data, char *line);

#endif
