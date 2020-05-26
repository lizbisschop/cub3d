/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/11 11:57:53 by liz           #+#    #+#                 */
/*   Updated: 2020/05/21 13:31:05 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void valid_map_check(int x, int y, t_data *data)
{
	// printf("%d\n", data->map.array_map_int[y][x]);
	if (data->map.array_map_int[y][x] == 1)
		return ;
	if (data->map.array_map_int[y][x] != 0)
	{
		return ;
	}
	if (x < 0 || y < 0 || y > data->map_height || x > data->map_width)
	{
		data->map.valid_map = 1;
		printf("int = %d | x =  %d | y = %d | width = %d | height = %d\n", data->map.array_map_int[y][x], x, y, data->map_width, data->map_height);
		// exit_program_please(data, "Not a valid map!!\n");
		return ;
	}
	data->map.array_map_int[y][x] = 9;
	valid_map_check(x + 1, y, data);
	valid_map_check(x, y + 1, data);
	valid_map_check(x - 1, y, data);
	valid_map_check(x, y - 1, data);
}

void change_map_back(int x, int y, t_data *data)
{
	if (data->map.array_map_int[y][x] == 9)
	{
		data->map.array_map_int[y][x] = 0;
		change_map_back(x + 1, y, data);
		change_map_back(x, y + 1, data);
		change_map_back(x - 1, y, data);
		change_map_back(x, y - 1, data);
	}
}