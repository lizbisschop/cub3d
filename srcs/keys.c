/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 11:45:37 by liz           #+#    #+#                 */
/*   Updated: 2020/06/05 16:51:45 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_release(int keycode, t_data *data)
{
	data->move.x = 0;
	return (0);
}

int		check_d(t_data *data, int keycode)
{
	if (keycode == D_KEY)
	{
		if (data->map.array_map_int[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x + data->ray.plane_x
			* data->ray.move_speed)] == 0)
			data->ray.pos_x += data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y
			+ data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] == 0)
			data->ray.pos_y += data->ray.plane_y
			* data->ray.move_speed;
	}
	return (0);
}

int		check_a(t_data *data, int keycode)
{
	if (keycode == A_KEY)
	{
		if (data->map.array_map_int[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x - data->ray.plane_x
			* data->ray.move_speed)] == 0)
			data->ray.pos_x -= data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y
			- data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] == 0)
			data->ray.pos_y -= data->ray.plane_y
			* data->ray.move_speed;
	}
	return (0);
}

int		key_input(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	data->move.x = 1;
	if (keycode == ESC || keycode == RED_CROSS)
		exit_program_please(data, "Window has been closed. Goodbye!\n");
	check_w(data, keycode);
	check_s(data, keycode);
	check_right(data, keycode);
	check_left(data, keycode);
	check_a(data, keycode);
	check_d(data, keycode);
	raycasting(data);
	return (0);
}
