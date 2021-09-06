/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_all_to_zero.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 11:31:04 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 17:30:15 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_all_to_zero_2(t_data *data)
{
	data->chars = 0;
	data->array = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->type_found = 0;
	data->not_map_string = 0;
	data->map_started = 0;
	data->map.map = NULL;
	data->save = 0;
	data->map_start = 0;
	data->map.color = -1;
	data->map.floor_color = -1;
	data->height = 0;
	data->width = 0;
}

void	set_all_to_zero(t_data *data)
{
	data->ray.x_ray = 0;
	data->map.valid_map = 0;
	data->move.w = 0;
	data->move.a = 0;
	data->move.l = 0;
	data->move.s = 0;
	data->move.d = 0;
	data->move.r = 0;
	data->ray.move_speed = 0.06;
	data->ray.rot_speed = 0.06;
	data->sprites.num_sprite = 0;
	data->sprites_count = 0;
	data->colors.r = -1;
	data->colors.g = -1;
	data->colors.b = -1;
	set_all_to_zero_2(data);
}
