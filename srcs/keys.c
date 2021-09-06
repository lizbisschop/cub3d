/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 11:45:37 by liz           #+#    #+#                 */
/*   Updated: 2020/06/19 12:20:00 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->move.w = 0;
	if (keycode == S_KEY)
		data->move.s = 0;
	if (keycode == D_KEY)
		data->move.d = 0;
	if (keycode == A_KEY)
		data->move.a = 0;
	if (keycode == ROTATE_LEFT)
		data->move.l = 0;
	if (keycode == ROTATE_RIGHT)
		data->move.r = 0;
	return (0);
}

void	check_d(t_data *data)
{
	if (data->move.d == 1)
	{
		if (data->map.array_map[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x + data->ray.plane_x
			* data->ray.move_speed)] != 1)
			data->ray.pos_x += data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map[(int)(data->ray.pos_y
			+ data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] != 1)
			data->ray.pos_y += data->ray.plane_y
			* data->ray.move_speed;
	}
}

void	check_a(t_data *data)
{
	if (data->move.a == 1)
	{
		if (data->map.array_map[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x - data->ray.plane_x
			* data->ray.move_speed)] != 1)
			data->ray.pos_x -= data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map[(int)(data->ray.pos_y
			- data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] != 1)
			data->ray.pos_y -= data->ray.plane_y
			* data->ray.move_speed;
	}
}

void	key_input(t_data *data)
{
	check_w(data);
	check_s(data);
	check_right(data);
	check_left(data);
	check_a(data);
	check_d(data);
}
