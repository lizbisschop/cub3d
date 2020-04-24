/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_filling.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:58:07 by liz           #+#    #+#                 */
/*   Updated: 2020/04/23 13:06:58 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int 	background(t_data *data, int col)
{
	int x = 0;
	int y = 0;

	while (y < data->height)
	{
		while (x < data->width)
		{
			my_mlx_pixel_put(data, x, y, col);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	return (0);
}

int 	draw_line(int x, int drawStart, int drawEnd, int color, t_data *data)
{
	int i;
	int y;
	
	y = drawStart;
	i = 0;

	while (i < drawStart)
	{
		my_mlx_pixel_put(data, x, i, 0xFFFF00FF);
		i++;
	}
	while (y <= drawEnd)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	while ( y < data->height)
	{
		my_mlx_pixel_put(data, x, y, 0xFF0000FF);
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
}