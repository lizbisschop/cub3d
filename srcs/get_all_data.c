/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_all_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:46:49 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 17:35:12 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		setting_mlx_2(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, data->width,
	data->height, "CUB3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->width, data->height);
	if (!data->mlx.img)
		exit_program_please("Error\nImage has not been created!\n");
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
	&data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	make_texture_no(data);
	make_texture_so(data);
	make_texture_ea(data);
	make_texture_we(data);
	make_texture_sprite(data);
	data->textures[5].tex = mlx_xpm_file_to_image(data->mlx.mlx,
	"./textures/wall_2.xpm", &data->textures[5].tex_width,
	&data->textures[5].tex_height);
	data->textures[6].tex = mlx_xpm_file_to_image(data->mlx.mlx,
	"./textures/floor.xpm", &data->textures[6].tex_width,
	&data->textures[6].tex_height);
	if (!data->textures[0].tex || !data->textures[1].tex ||
	!data->textures[2].tex || !data->textures[3].tex || !data->textures[4].tex)
		exit_program_please("Error\nSomething wrong with textures\n");
	return (0);
}

int		setting_mlx(t_data *data)
{
	int i;

	i = 0;
	if (data->map.color < 0 || data->map.floor_color < 0)
		exit_program_please("Error\nColors are nor there\n");
	if (data->width == 0 || data->height == 0)
		exit_program_please("Error\nNo height and width\n");
	setting_mlx_2(data);
	data->sprites.zbuffer = malloc(sizeof(double) * data->width);
	if (!data->sprites.zbuffer)
		exit_program_please("Error\nMalloc has failed!\n");
	return (0);
}

void	get_all_data(t_data *data, char **argv)
{
	int x;
	int y;
	int i;

	i = 0;
	save_map_in_array(data, argv);
	if (!data->map.map)
		exit_program_please("Error\nThere is no map!!\n");
	if (!data->map.no_path || !data->map.so_path ||
	!data->map.ea_path || !data->map.we_path || !data->map.sprite)
		exit_program_please("Error\nMalloc has failed!\n");
	setting_mlx(data);
	make_int_array(data);
	data->sprites.sprite_order = malloc(sizeof(int) * data->sprites.num_sprite);
	data->sprites.sprite_distance = malloc(sizeof(double)
	* data->sprites.num_sprite);
	if (!data->sprites.sprite_order || !data->sprites.sprite_distance)
		exit_program_please("Error\nMalloc has failed!\n");
	x = (int)data->ray.pos_x;
	y = (int)data->ray.pos_y;
	valid_map_check(x, y, data);
	check_type(data);
	change_map_back(x, y, data);
	if (data->map.valid_map == 1)
		exit_program_please("Error\nNot a valid map!!\n");
}
