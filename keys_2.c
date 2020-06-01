/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 13:24:43 by liz           #+#    #+#                 */
/*   Updated: 2020/05/29 13:24:55 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_left(t_data *data, int keycode)
{
	if (keycode == ROTATE_LEFT)
	{
		data->ray.old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed)
		- data->ray.dir_y * sin(-data->ray.rot_speed);
		data->ray.dir_y = data->ray.old_dir_x * sin(-data->ray.rot_speed)
		+ data->ray.dir_y * cos(-data->ray.rot_speed);
		data->ray.old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed)
		- data->ray.plane_y * sin(-data->ray.rot_speed);
		data->ray.plane_y = data->ray.old_plane_x * sin(-data->ray.rot_speed)
		+ data->ray.plane_y * cos(-data->ray.rot_speed);
	}
}

int		check_right(t_data *data, int keycode)
{
	if (keycode == ROTATE_RIGHT)
	{
		data->ray.old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed)
		- data->ray.dir_y * sin(data->ray.rot_speed);
		data->ray.dir_y = data->ray.old_dir_x * sin(data->ray.rot_speed)
		+ data->ray.dir_y * cos(data->ray.rot_speed);
		data->ray.old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed)
		- data->ray.plane_y * sin(data->ray.rot_speed);
		data->ray.plane_y = data->ray.old_plane_x * sin(data->ray.rot_speed)
		+ data->ray.plane_y * cos(data->ray.rot_speed);
	}
}

int		check_s(t_data *data, int keycode)
{
	if (keycode == S_KEY)
	{
		if (data->map.array_map_int[(int)(data->ray.pos_y)]
		[(int)(data->ray.pos_x
		- data->ray.dir_x * data->ray.move_speed)] != 1)
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y - data->ray.dir_y
		* data->ray.move_speed)][(int)(data->ray.pos_x)] != 1)
			data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	}
}

int		check_w(t_data *data, int keycode)
{
	if (keycode == W_KEY)
	{
		if (data->map.array_map_int[(int)(data->ray.pos_y)]
		[(int)(data->ray.pos_x
		+ data->ray.dir_x * data->ray.move_speed)] != 1)
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y + data->ray.dir_y
		* data->ray.move_speed)][(int)(data->ray.pos_x)] != 1)
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	}
}
