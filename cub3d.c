/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:36 by liz            #+#    #+#                */
/*   Updated: 2020/03/24 19:06:52 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int x = 20;
	int y = 20;
	int a = 0;
	int b = 0;
	int j = 0;
	int k = 0;
	int h = 5;
	int i = 5;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1010, 700, "hello world");
    img.img = mlx_new_image(mlx, 1010, 700);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF00);
	// 	my_mlx_pixel_put(&img, 10, 10, 0x0000FF00);
	// 	my_mlx_pixel_put(&img, 15, 15, 0xFF0000);
	// 	my_mlx_pixel_put(&img, 20, 20, 0xFFFFFF);
	// 	my_mlx_pixel_put(&img, 25, 25, 0x0000FF00);
	// 	my_mlx_pixel_put(&img, 30, 30, 0xFFFF00);
	// 	my_mlx_pixel_put(&img, 35, 35, 0xFFFFFF);
	// 		my_mlx_pixel_put(&img, 40, 40, 0x0000FF00);
	// 	my_mlx_pixel_put(&img, 45, 45, 0xFF0000);
	// 	my_mlx_pixel_put(&img, 50, 50, 0xFFFFFF);
	// 	my_mlx_pixel_put(&img, 55, 55, 0x0000FF00);
	// 	my_mlx_pixel_put(&img, 60, 60, 0xFFFF00);
	// 	my_mlx_pixel_put(&img, 65, 65, 0xFF0000);
		while (j < 700)
	{
		my_mlx_pixel_put(&img, j, k, 0x0000FF00);
		j = j + 10;
		k = k + 10;
	}
		while(h < 700)
		{
			my_mlx_pixel_put(&img, h, i, 0xFFFF00FF);
			h = h + 4;
			i = i + 4;
		}
	while (1)
	{
    	mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
		mlx_put_image_to_window(mlx, mlx_win, img.img, y, (x + 10));
		mlx_put_image_to_window(mlx, mlx_win, img.img, a, b);
		a = a + 20;
		b = b + 20;
		y = y + 50;
	}
	mlx_loop(mlx);
    return (0);
}

