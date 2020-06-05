/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 10:39:35 by liz           #+#    #+#                 */
/*   Updated: 2020/06/05 12:21:55 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		which_texture(t_data *data)
{
	if (data->ray.map_x <= data->ray.pos_x)
	{
		if (data->ray.side == 0)
			data->tex.tex_num = 2;
		if (data->ray.pos_y < data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = 1;
		else if (data->ray.pos_y > data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = 0;
	}
	else if (data->ray.map_x > data->ray.pos_x)
	{
		if (data->ray.side == 0)
			data->tex.tex_num = 3;
		if (data->ray.pos_y < data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = 1;
		else if (data->ray.pos_y > data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = 0;
	}
	return (0);
}

int		draw_textures_2(t_data *data)
{
	int color;
	int y;

	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->tex.tex_y = (int)data->tex.tex_pos &
		(data->textures[data->tex.tex_num].tex_height - 1);
		data->tex.tex_pos += data->tex.step;
		color = (data->textures[data->tex.tex_num].texture_adrr
		[data->textures[data->tex.tex_num].tex_height * data->tex.tex_y
		+ data->tex.tex_x]);
		my_mlx_pixel_put(data, data->ray.x_ray, y, color);
		y++;
	}
	return (0);
}

int		draw_textures(t_data *data)
{
	int color;
	int y;
	int i;

	i = 0;
	y = data->ray.draw_end;
	while (i < data->ray.draw_start)
	{
		my_mlx_pixel_put(data, data->ray.x_ray, i, data->map.color);
		i++;
	}
	draw_textures_2(data);
	while (y < data->height)
	{
		my_mlx_pixel_put(data, data->ray.x_ray, y, data->map.floor_color);
		y++;
	}
	return (0);
}

int		textures_make(t_data *data)
{
	if (data->ray.side == 0)
		data->tex.wall_x = data->ray.pos_y + data->ray.perp_wall_dist
		* data->ray.ray_dir_y;
	else
		data->tex.wall_x = data->ray.pos_x + data->ray.perp_wall_dist
		* data->ray.ray_dir_x;
	data->tex.wall_x -= floor((data->tex.wall_x));
	data->tex.tex_x = (int)(data->tex.wall_x *
	(double)(data->textures[data->tex.tex_num].tex_width));
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->tex.tex_x = data->textures[data->tex.tex_num].tex_width
		- data->tex.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->tex.tex_x = data->textures[data->tex.tex_num].tex_width
		- data->tex.tex_x - 1;
	data->tex.step = 1.0 * data->textures[data->tex.tex_num].tex_height
	/ data->ray.line_height;
	data->tex.tex_pos = (data->ray.draw_start - data->height
	/ 2 + data->ray.line_height / 2) * data->tex.step;
	draw_textures(data);
	return (0);
}
