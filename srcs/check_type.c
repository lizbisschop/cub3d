/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 13:34:48 by liz           #+#    #+#                 */
/*   Updated: 2020/06/01 11:32:43 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_type_2(t_data *data)
{
	if (data->ray.type == 'N')
	{
		data->ray.dir_y = -1;
		data->ray.dir_x = 0.0;
		data->ray.plane_x = 0.66;
		data->ray.plane_y = 0.0;
	}
	else if (data->ray.type == 'S')
	{
		data->ray.dir_y = 1.0;
		data->ray.dir_x = 0.0;
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0.0;
	}
}

int		check_type(t_data *data)
{
	if (data->ray.type == 'E')
	{
		data->ray.dir_y = 0.0;
		data->ray.dir_x = 1.0;
		data->ray.plane_x = 0.0;
		data->ray.plane_y = 0.66;
	}
	else if (data->ray.type == 'W')
	{
		data->ray.dir_y = 0.0;
		data->ray.dir_x = -1;
		data->ray.plane_x = 0.0;
		data->ray.plane_y = -0.66;
	}
	check_type_2(data);
}
