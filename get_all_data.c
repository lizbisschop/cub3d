/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_all_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:46:49 by liz           #+#    #+#                 */
/*   Updated: 2020/05/12 13:48:14 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	check_type(t_data *data)
{
	if (data->ray.type == 'E')
	{
		data->ray.dirY = 1.0;
		data->ray.dirX = 0.0;
		data->ray.planeX = 0.66;
		data->ray.planeY = 0.0;
	}
	else if (data->ray.type == 'W')
	{
		data->ray.dirY = -1;
		data->ray.dirX = 0.0;
		data->ray.planeX = -0.66;
		data->ray.planeY = 0.0;
	}
	else if (data->ray.type == 'N')
	{
		data->ray.dirY = 0.0;
		data->ray.dirX = -1;
		data->ray.planeX = 0.0;
		data->ray.planeY = 0.66;
	}
	else if (data->ray.type == 'S')
	{
		data->ray.dirY = 0.0;
		data->ray.dirX = 1.0;
		data->ray.planeX = 0.0;
		data->ray.planeY = -0.66;
	}
}

int 	setting_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, 1010, 700, "CUB3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, 1010, 700);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	int i = 0;
	
}

int setting_raycasting(t_data *data)
{
	data->ray.x_ray = 0;
	data->map.valid_map = 0;
	data->error.check_double_R = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->ray.moveSpeed = 0.09;
	data->ray.rotSpeed = 0.09;
	


}

int 	get_all_data(t_data *data, char **argv)
{
	int x;
	int y;

	setting_mlx(data);
	setting_raycasting(data);
	data->str_cnt = save_map_in_array(data, argv);
	// print_rectangle(30, 30, 80, 80, data->map.floor_color, data);
	// print_rectangle(130, 130, 80, 80, data->map.color, data);
	// make_char_array(data);
	make_int_array(data);
	x = data->ray.posX;
	y = data->ray.posY;
	valid_map_check(x, y, data);
	check_type(data);
	// printf("%s\n", data->map.map);
	// printf("hello\n");
	// printf("%d\n%s\n", data->map.valid_map, data->map.map);
	x = 0;
	y = 0;
	// printf("%d  ||  %d\n", data->map_width, data->map_height);
	// printf("%s\n", data->map.map);
	// while(x < data->map_width)
	// {
	// 	while (y < data->map_height)
	// 	{
	// 		printf("|%d|", data->map.array_map_int[x][y]);
	// 		y++;
	// 	}
	// 	x++;
	// 	y = 0;
	// 	printf("\n");
	// }
	if (data->map.valid_map == 1)
		exit_program_please(data, "Not a valid map!!\n");
	x = 0;
	y = 0;
	change_map_back(data->ray.posX, data->ray.posY, data);
}