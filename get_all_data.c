/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_all_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:46:49 by liz           #+#    #+#                 */
/*   Updated: 2020/05/26 11:54:37 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	check_type(t_data *data)
{
	if (data->ray.type == 'E')
	{
		data->ray.dir_y = 1.0;
		data->ray.dir_x = 0.0;
		data->ray.plane_x = 0.66;
		data->ray.plane_y = 0.0;
	}
	else if (data->ray.type == 'W')
	{
		data->ray.dir_y = -1;
		data->ray.dir_x = 0.0;
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0.0;
	}
	else if (data->ray.type == 'N')
	{
		data->ray.dir_y = 0.0;
		data->ray.dir_x = -1;
		data->ray.plane_x = 0.0;
		data->ray.plane_y = 0.66;
	}
	else if (data->ray.type == 'S')
	{
		data->ray.dir_y = 0.0;
		data->ray.dir_x = 1.0;
		data->ray.plane_x = 0.0;
		data->ray.plane_y = -0.66;
	}
}

int 	setting_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, data->width, data->height, "CUB3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->width, data->height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	data->textures[0].tex = mlx_xpm_file_to_image(data->mlx.mlx, data->map.no_path, &data->textures[0].tex_width, &data->textures[0].tex_height);
	data->textures[1].tex = mlx_xpm_file_to_image(data->mlx.mlx, data->map.so_path, &data->textures[1].tex_width, &data->textures[1].tex_height);
	data->textures[2].tex = mlx_xpm_file_to_image(data->mlx.mlx, data->map.we_path, &data->textures[2].tex_width, &data->textures[2].tex_height);
	data->textures[3].tex = mlx_xpm_file_to_image(data->mlx.mlx, data->map.ea_path, &data->textures[3].tex_width, &data->textures[3].tex_height);
	data->textures[4].tex = mlx_xpm_file_to_image(data->mlx.mlx, data->map.sprite, &data->textures[4].tex_width, &data->textures[4].tex_height);
	int i = 0;
	data->buffer = malloc(sizeof(unsigned int *) * data->height);
	while (i < data->height)
	{
		data->buffer[i] = malloc(sizeof(unsigned int ) * data->width);
		i++;
	}
	data->zbuffer = malloc(sizeof(double) * data->width);
	
}

int setting_raycasting(t_data *data)
{
	data->ray.x_ray = 0;
	data->map.valid_map = 0;
	data->error.check_double_R = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->ray.move_speed = 0.09;
	data->ray.rot_speed = 0.09;	
}

int 	get_all_data(t_data *data, char **argv)
{
	int x;
	int y;

	save_map_in_array(data, argv);
	setting_mlx(data);
	setting_raycasting(data);
	// printf("%s\n", data->map.map);
	// print_rectangle(30, 30, 80, 80, data->map.floor_color, data);
	// print_rectangle(130, 130, 80, 80, data->map.color, data);
	// make_char_array(data);
	make_int_array(data);
	int i = 0;
	// data->buffer = malloc(sizeof(int) * (data->height + 1));
	// while (i < data->width)
	// {
	// 	data->buffer[i] = ft_calloc(data->width + 1, sizeof(int *));
	// 	i++;
	// }
	// data->zbuffer = malloc(sizeof(int) * data->width);
	x = (int)data->ray.pos_x;
	y = (int)data->ray.pos_y;
	valid_map_check(x, y, data);
	check_type(data);
	// printf("%s\n", data->map.map);
	// printf("hello\n");
	// printf("%d\n%s\n", data->map.valid_map, data->map.map);
	if (data->map.valid_map == 1)
		exit_program_please(data, "Not a valid map!!\n");
	// x = 0;
	// y = 0;
	change_map_back(x, y, data);
// 	int i = 0;
// 	int j = 0;
// 	while (j < data->map_height)
// 	{
// 		while (i < data->map_width)
// 		{
// 			printf("%d", data->map.array_map_int[j][i]);
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 		printf("\n");
// 	}
}