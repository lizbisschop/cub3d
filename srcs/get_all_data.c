/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_all_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:46:49 by liz           #+#    #+#                 */
/*   Updated: 2020/06/05 15:49:19 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		setting_mlx_2(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, data->width,
	data->height, "CUB3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->width, data->height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
	&data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	if (ft_strnstr(data->map.no_path, "xpm", ft_strlen(data->map.no_path)))
	{
	data->textures[0].tex = mlx_xpm_file_to_image(data->mlx.mlx,
	data->map.no_path, &data->textures[0].tex_width,
	&data->textures[0].tex_height);
	}
	else
	{
		data->textures[0].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.no_path, &data->textures[0].tex_width,
		&data->textures[0].tex_height);
	}
	if (ft_strnstr(data->map.so_path, "xpm", ft_strlen(data->map.so_path)))
	{
	data->textures[1].tex = mlx_xpm_file_to_image(data->mlx.mlx,
	data->map.so_path, &data->textures[1].tex_width,
	&data->textures[1].tex_height);
	}
	else
	{
		data->textures[1].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.so_path, &data->textures[1].tex_width,
		&data->textures[1].tex_height);
	}
	if (ft_strnstr(data->map.we_path, "xpm", ft_strlen(data->map.we_path)))
	{
		data->textures[2].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.we_path, &data->textures[2].tex_width,
		&data->textures[2].tex_height);
	}
	else 
	{
		data->textures[2].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.we_path, &data->textures[2].tex_width,
		&data->textures[2].tex_height);
	}
	if (ft_strnstr(data->map.ea_path, "xpm", ft_strlen(data->map.ea_path)))
	{
		data->textures[3].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.ea_path, &data->textures[3].tex_width,
		&data->textures[3].tex_height);
	}
	else
	{
		data->textures[3].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.ea_path, &data->textures[3].tex_width,
		&data->textures[3].tex_height);
	}
	if (ft_strnstr(data->map.sprite, "xpm", ft_strlen(data->map.sprite)))
	{
	data->textures[4].tex = mlx_xpm_file_to_image(data->mlx.mlx,
	data->map.sprite, &data->textures[4].tex_width,
	&data->textures[4].tex_height);
	}
	else
	{
		data->textures[4].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.sprite, &data->textures[4].tex_width,
		&data->textures[4].tex_height);
	}
	if (!data->textures[0].tex || !data->textures[1].tex ||
	!data->textures[2].tex || !data->textures[3].tex || !data->textures[4].tex)
		exit_program_please(data, "Something wrong with textures\n");
	return (0);
}

int		setting_mlx(t_data *data)
{
	int i;

	i = 0;
	setting_mlx_2(data);
	data->zbuffer = malloc(sizeof(double) * data->width);
	if (!data->zbuffer)
		exit_program_please(data, "Malloc has failed!\n");
	return (0);
}

int		setting_raycasting(t_data *data)
{
	data->ray.x_ray = 0;
	data->map.valid_map = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->ray.move_speed = 0.09;
	data->ray.rot_speed = 0.09;
	return (0);
}

int		get_all_data(t_data *data, char **argv)
{
	int x;
	int y;

	data->num_sprite = 0;
	data->sprites = 0;
	data->chars = 0;
	data->array = 0;
	save_map_in_array(data, argv);
	int i = 0;
	int j = 0;
	if (!data->map.no_path || !data->map.so_path ||
	!data->map.ea_path || !data->map.we_path || !data->map.sprite)
		exit_program_please(data, "Malloc has failed!\n");
	setting_mlx(data);
	setting_raycasting(data);
	make_int_array(data);
	data->sprite_order = malloc(sizeof(int) * data->num_sprite);
	data->sprite_distance = malloc(sizeof(double) * data->num_sprite);
	if (!data->sprite_order || !data->sprite_distance)
		exit_program_please(data, "Malloc has failed!\n");
	x = (int)data->ray.pos_x;
	y = (int)data->ray.pos_y;
	valid_map_check(x, y, data);
	check_type(data);
	if (data->map.valid_map == 1)
		exit_program_please(data, "Not a valid map!!\n");
	change_map_back(x, y, data);
	return (0);
}
