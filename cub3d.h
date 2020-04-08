/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:12 by liz           #+#    #+#                 */
/*   Updated: 2020/04/08 14:31:08 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "./mlx/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

//KEYS
#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100


// typedef struct	s_data {
// 	void	*mlx;
// 	void	*win;
// }				t_data;

typedef struct s_data {
	void	*mlx;
	int 	xw;
	int 	yw;
	// int x;
	int y;
	int		width;
	int 	height;
	void	*mlx_win;
    void    *img;
    char    *addr;
	int 	floor_color;
	char	*map;
	void	*NO_texture;
	void	*SO_texture;
	void	*EA_texture;
	void	*WE_texture;
	void	*sprite;
	int		str_cnt;
	int 	color;
	int		r;
	int		g;
	int 	b;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	int		img_width;
	int		img_height;
	void	*img_ptr;


	//raycasting
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int x;
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
	// int color;
	double oldDirX;
	double oldDirY;
	double oldPlaneX;
	double oldPlaneY;


}           t_data;


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

int 	save_textures(t_data *data);
int		map_int_array(t_data *data);

//LIBFT FILES
int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);

#endif