/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_casting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 10:42:30 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/18 12:54:42 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	while_loop_floor_casting(t_data *data, int y)
{
	int x;

	x = 0;
	while (x < data->width)
	{
		data->floor.cell_x = (int)(data->floor.floor_x);
		data->floor.cell_y = (int)(data->floor.floor_y);
		data->floor.tx = (int)(data->textures[1].tex_width *
		(data->floor.floor_x - data->floor.cell_x)) &
		(data->textures[1].tex_width - 1);
		data->floor.ty = (int)(data->textures[1].tex_height *
		(data->floor.floor_y - data->floor.cell_y)) &
		(data->textures[1].tex_height - 1);
		data->floor.floor_x += data->floor.floor_step_x;
		data->floor.floor_y += data->floor.floor_step_y;
		data->color = data->textures[6].texture_adrr[data->textures[1].tex_width
		* data->floor.ty + data->floor.tx];
		data->color = (data->color >> 1) & 8355711;
		my_mlx_pixel_put(data, x, y, data->color);
		data->color = data->textures[5].texture_adrr[data->textures[1].tex_width
		* data->floor.ty + data->floor.tx];
		data->color = (data->color >> 1) & 8355711;
		my_mlx_pixel_put(data, x, data->height - y - 1, data->color);
		x++;
	}
}

void	floor_casting(t_data *data)
{
	int y;
	int p;
	int color;

	y = 0;
	while (y < data->height)
	{
		data->floor.ray_dir_x0 = data->ray.dir_x - data->ray.plane_x;
		data->floor.ray_dir_y0 = data->ray.dir_y - data->ray.plane_y;
		data->floor.ray_dir_x1 = data->ray.dir_x + data->ray.plane_x;
		data->floor.ray_dir_y1 = data->ray.dir_y + data->ray.plane_y;
		p = y - data->height / 2;
		data->floor.pos_z = 0.5 * data->height;
		data->floor.row_distance = data->floor.pos_z / p;
		data->floor.floor_step_x = data->floor.row_distance *
		(data->floor.ray_dir_x1 - data->floor.ray_dir_x0) / data->width;
		data->floor.floor_step_y = data->floor.row_distance *
		(data->floor.ray_dir_y1 - data->floor.ray_dir_y0) / data->width;
		data->floor.floor_x = data->ray.pos_x + data->floor.row_distance
		* data->floor.ray_dir_x0;
		data->floor.floor_y = data->ray.pos_y + data->floor.row_distance
		* data->floor.ray_dir_y0;
		while_loop_floor_casting(data, y);
		y++;
	}
}
