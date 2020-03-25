/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:36 by liz            #+#    #+#                */
/*   Updated: 2020/03/25 15:56:54 by liz           ########   odam.nl         */
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
	int x = 5;
	int y = 5;
	int i = 130;
	int j = 130;
	int k = 130;
	int a = 300;
	int b = 300;
	int color = 0xa52a2a + 1;


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1010, 700, "hello world");
    img.img = mlx_new_image(mlx, 1010, 700);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while (i < 600)
	{
		while(y < i)
		{
			while (x < i)
			{
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
			x = 5;
			y++;
			color = color + 20;
			mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
		}
		i++;
		y = 5;
		
		// y = 5;
	}
	// while (j < 330)
	// {
	// 	while(i < k && k < 230)
	// 	{
	// 		my_mlx_pixel_put(&img, i, j, 0xFFFF0000);
	// 		i++;
	// 	}
	// 	i = 130;
	// 	j++;
	// 	k = k + 2;
	// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, i, k);
	// }
	// int r = 30;
	// while (r > 0)
	// {
	// 	int xc = 300, yc = 300;
	// 	int u = 0, w = r;
	// 	int d = 3 - 2 * r;
	// 	while ( w >= u)
	// 	{
	// 		u++;
	// 		if (d > 0)
	// 		{
	// 			w--;
	// 			d = d + 4 * (u - w) + 10;
	// 		}
	// 		else
	// 			d = d + 4 * u + 6;
	// 		my_mlx_pixel_put(&img, xc+u, yc+w, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&imcg, xc-u, yc+w, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc+u, yc-w, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc-u, yc-w, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc+w, yc+u, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc-w, yc+u, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc+w, yc-u, 0xFF00FFFF); 
    // 		my_mlx_pixel_put(&img, xc-w, yc-u, 0xFF00FFFF); 	
	// 	}
	// 	r--;
	// }
		// mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
				
	mlx_loop(mlx);
    return (0);
}

