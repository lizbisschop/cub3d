#ifndef CUB3D_IRIS_H
#define CUB3D_IRIS_H

#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct      s_info{
    int             resolution_x;
    int             resolution_y;
    char            *path_NO;
    char            *path_SO;
    char            *path_WE;
    char            *path_EA;
    char            *path_S;
    int             col_floor;
    int             col_ceiling;
    char            *whole_map;
    int             xmax;
    int             ymax;
    int             xstart;
    int             ystart;
    char            type;
}                   t_info;
typedef struct      s_vars {
    void            *mlx;
    void            *win;
    int             wid;
    int             hei;
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
    int             x;
    int             y;
    int             xw;
    int             yw;
    unsigned int    col;
    unsigned int    r;
    unsigned int    g;
    unsigned int    b;
    int             img_width;
    int             img_height;
    t_info          map;
    char            *array;
}                   t_vars;
// 
// #ifndef EVENT_KEY_PRESS 


int		render_next_frame(t_vars *vars);
int     wasd(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int 	print_rectangle(int xw, int yw, int height, int width, unsigned int col, t_vars *vars);

#endif