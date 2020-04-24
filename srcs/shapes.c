/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 19:36:51 by liz           #+#    #+#                 */
/*   Updated: 2020/04/22 11:07:32 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(b << 24 | g << 16 | r << 8 | t);
}


int 	print_rectangle(int xw, int yw, int height, int width, unsigned int col, t_data *data)
{
	int x = 0;
	int y = 0;
	int xstart = xw;
	while(y < 80)
	{
		while (x < 80)
		{
			my_mlx_pixel_put(data, xw, yw, col);
			xw++;
			x++;
		}
		x =0;
		xw = xstart;
		yw++;
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
}

int		print_circle(int x, int y, int r, t_data *data)
{
		x = 0;
		y = r;
		int xc = 300, yc = 300;
		int d = 3 - 2 * r;
		while ( y >= x)
		{
			x++;
			if (d > 0)
			{
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else
				d = d + 4 * x + 6;
			my_mlx_pixel_put(data, xc+x, yc+y, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc-x, yc+y, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc+x, yc-y, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc-x, yc-y, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc+y, yc+x, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc-y, yc+x, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc+y, yc-x, 0xFF00FFFF); 
    		my_mlx_pixel_put(data, xc-y, yc-x, 0xFF00FFFF); 	
		}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	}