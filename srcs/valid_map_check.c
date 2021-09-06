/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/11 11:57:53 by liz           #+#    #+#                 */
/*   Updated: 2020/06/19 12:20:25 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		valid_map_check(int x, int y, t_data *data)
{
	if (data->map.array_map[y][x] == 1)
		return ;
	if (data->map.array_map[y][x] != 0 &&
	data->map.array_map[y][x] != 2)
		return ;
	if (x <= 0 || y <= 0 || y == data->map_height - 1 ||
	x == data->map_width - 1)
	{
		data->map.valid_map = 1;
		return ;
	}
	data->map.array_map[y][x] = 9;
	valid_map_check(x + 1, y, data);
	valid_map_check(x, y + 1, data);
	valid_map_check(x - 1, y, data);
	valid_map_check(x, y - 1, data);
	valid_map_check(x + 1, y + 1, data);
	valid_map_check(x + 1, y + 1, data);
	valid_map_check(x - 1, y - 1, data);
	valid_map_check(x - 1, y - 1, data);
}

void		change_map_back(int x, int y, t_data *data)
{
	if (data->map.array_map[y][x] == 9)
	{
		data->map.array_map[y][x] = 0;
		change_map_back(x + 1, y, data);
		change_map_back(x, y + 1, data);
		change_map_back(x - 1, y, data);
		change_map_back(x, y - 1, data);
	}
}
