/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings->c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student->codam->nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/12 15:21:50 by liz           #+#    #+#                 */
/*   Updated: 2020/04/12 15:25:15 by liz           ########   odam->nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_struct(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1010, 700, "CUB3D");
	data->img = mlx_new_image(data->mlx, 1010, 700);
	data->width = 1010;
	data->height = 700;
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

	data->str_cnt = save_map_in_array(data);
	make_char_array(data);
	make_int_array(data);
	data->valid_map = 0;
	int x = 0;
	int y = 0;

	valid_map_check(0, 0, data);
	if (data->valid_map == 1)
	{
		printf("not a valid map!\n");
		exit(0);
	}
	change_map_back(0, 0, data);

	data->posX = 22;
	data->posY = 12;
	data->planeX = 0;
	data->planeY = 0.66;
	data->time = 0;
	data->oldTime = 0;
	data->x = 0;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->EA_texture, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->SO_texture, 500, 500);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->WE_texture, 100, 100);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->NO_texture, 200, 200);


	while(x < data->xw)
	{
		while (y < data->yw)
		{
			printf("%c", data->array_map_char[x][y]);
			y++;
		}
		x++;
		y = 0;
		printf("\n");
	}


	mlx_loop(data->mlx);

}