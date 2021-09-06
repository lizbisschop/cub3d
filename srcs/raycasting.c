/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 11:22:49 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 16:48:03 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		what_to_draw(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.map_x - data->ray.pos_x +
		(1 - data->ray.step_x) / 2) / data->ray.ray_dir_x;
	else
		data->ray.perp_wall_dist = (data->ray.map_y - data->ray.pos_y +
		(1 - data->ray.step_y) / 2) / data->ray.ray_dir_y;
	data->ray.line_height = (int)(data->height / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + data->height / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + data->height / 2;
	if (data->ray.draw_end >= data->height)
		data->ray.draw_end = data->height - 1;
	textures_make(data);
	data->sprites.zbuffer[data->ray.x_ray] = data->ray.perp_wall_dist;
	data->ray.x_ray++;
	return (0);
}

int		wall_is_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map.array_map[data->ray.map_y][data->ray.map_x] == 1)
		{
			data->ray.hit = 1;
			which_texture(data);
		}
	}
	return (0);
}

int		calculating_step(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pos_x - data->ray.map_x)
		* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pos_x)
		* data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y)
		* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pos_y)
		* data->ray.delta_dist_y;
	}
	return (0);
}

int		raycasting_loop(t_data *data)
{
	data->ray.camera_x = 2 * data->ray.x_ray / (double)data->width - 1;
	data->ray.ray_dir_x = data->ray.dir_x +
	data->ray.plane_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y +
	data->ray.plane_y * data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.hit = 0;
	data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
	calculating_step(data);
	wall_is_hit(data);
	what_to_draw(data);
	return (0);
}

int		raycasting(t_data *data)
{
	key_input(data);
	data->ray.x_ray = 0;
	while (data->ray.x_ray < data->width)
		raycasting_loop(data);
	sprites(data);
	if (data->save == 0)
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->mlx.img, 0, 0);
	return (0);
}
