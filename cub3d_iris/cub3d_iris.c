/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_iris.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 09:51:25 by iboeters       #+#    #+#                */
/*   Updated: 2020/04/01 20:09:24 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_iris.h"

//mlx_pixel_put is very slow: push pixel instantly without waiting for rendering whole image -->
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char *dst;

	if (x <= vars->wid && x >= 0 && y >= 0 && y <= vars->hei)
    {
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int 	print_rectangle(int xw, int yw, int height, int width, unsigned int col, t_vars *vars)
{
	int x = 0;
	int y = 0;
	while(y < 80)
	{
		while (x < 80)
		{
			my_mlx_pixel_put(vars, xw, yw, col);
			xw++;
			x++;
		}
		x =0;
		xw = vars->xw;
		yw++;
		y++;
	}
}


int		return_error(char *error)
{
	perror(error);
	return(0);
}

int		main(int argc, char **argv)
{
	t_vars			vars;
	int				img_height;
	int				img_heigth;

	vars.wid = 600;
	vars.hei = 600;
	vars.x = 0;
	vars.y = 200;
	vars.r = 255;
	vars.g = 0;
	vars.b = 126;
	// if (argc == 2)
	// {
	// 	if (parse(argv, &vars) == -1)
	// 		return (0);
	// }
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return(return_error("Error: failed to connect to display!"));
	vars.win = mlx_new_window(vars.mlx, vars.wid, vars.hei, "cube3D");
	if(vars.win == NULL)
		return(return_error("Error: failed to create new window!"));
	mlx_clear_window(vars.mlx, vars.win);
	vars.img = mlx_new_image(vars.mlx, vars.wid, vars.hei);
	if(vars.img == NULL)
		return(return_error("Error: faied to create new image!"));
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	//shapes(&vars);
	// hooks(&vars);
	vars.xw = 0;
    vars.yw = 0;
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	// mlx_hook(vars.win, 3, 1l<<1, wasd, &vars);
	// images(&vars);
	mlx_loop(vars.mlx);
	return(0);
}
