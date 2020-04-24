/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_all_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:46:49 by liz           #+#    #+#                 */
/*   Updated: 2020/04/23 14:24:13 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	setting_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 1010, 700, "CUB3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, 1010, 700);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
}

int setting_raycasting(t_data *data)
{
	data->ray.dirX = -1;
	data->ray.dirY = 0;
	data->ray.planeX = 0;
	data->ray.planeY = 0.66;
	data->ray.time = 0;
	data->ray.oldTime = 0;
	data->ray.x_ray = 0;
	data->map.valid_map = 0;
	data->error.check_double = 0;
	data->move.x = 0;
	data->move.y = 0;

}

int 	get_all_data(t_data *data)
{
	int x;
	int y;

	// get_structs(data);
	// x = data->ray.posX;
	// y = data->ray.posY;
	setting_mlx(data);

	data->str_cnt = save_map_in_array(data);
	// make_char_array(data);
	make_int_array(data);
	setting_raycasting(data);
	valid_map_check(x, y, data);
	x = 0;
	y = 0;
	// printf("hello\n");
	if (data->map.valid_map == 1 || !ft_strchr(data->map.map, '0'))
		exit_program_please(data, "Not a valid map!!\n");
	x = 0;
	y = 0;
	change_map_back(x, y, data);
	// // printf("%d  ||  %d\n", data->xw, data->yw);
	// while(x < data->xw)
	// {
	// 	while (y < data->yw)
	// 	{
	// 		printf("%d", data->map.array_map_int[x][y]);
	// 		y++;
	// 	}
	// 	x++;
	// 	y = 0;
	// 	printf("\n");
	// }
}