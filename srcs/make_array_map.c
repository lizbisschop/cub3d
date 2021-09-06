/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_array_map.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 10:44:01 by liz           #+#    #+#                 */
/*   Updated: 2020/06/25 17:13:58 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		malloc_array_map(t_data *data)
{
	int i;

	i = 0;
	data->map.array_map = malloc(sizeof(int*) * data->map_height + 1);
	while (i < data->map_height)
	{
		data->map.array_map[i] =
		ft_calloc(data->map_width + 1, sizeof(int));
		if (!data->map.array_map[i])
			exit_program_please("Error\nMalloc has failed!\n");
		i++;
	}
	if (!data->map.array_map)
		exit_program_please("Error\nMalloc has failed!\n");
	return (0);
}

int		save_map_width_height(t_data *data)
{
	int i;
	int total_chars;

	i = 0;
	total_chars = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
			data->map_height++;
			if (data->map_width > total_chars)
				total_chars = (data->map_width - 1);
			data->map_width = 0;
		}
		if (data->map.map[i] == ' ')
			i++;
		i++;
		data->map_width++;
	}
	data->map_width = total_chars;
	malloc_array_map(data);
	return (0);
}

int		if_statements_array(t_data *data, int i)
{
	if (data->map.map[i] == '\n')
	{
		data->chars = 0;
		data->array++;
	}
	if (data->map.map[i] == 'N' || data->map.map[i] == 'S' ||
	data->map.map[i] == 'W' || data->map.map[i] == 'E')
	{
		if (data->type_found != 0)
			exit_program_please("Error\nDouble type declaration\n");
		data->type_found++;
		data->ray.type = data->map.map[i];
		data->ray.pos_x = (double)data->chars + 0.5;
		data->ray.pos_y = (double)data->array + 0.5;
		data->map.array_map[data->array][data->chars] = 0;
		data->chars++;
	}
	if (data->map.map[i] == ' ')
	{
		data->map.array_map[data->array][data->chars] = 0;
		data->chars++;
	}
	return (0);
}

int		save_int_array(t_data *data)
{
	int i;

	i = 0;
	while (data->map.map[i] != '\0')
	{
		if_statements_array(data, i);
		if (data->map.map[i] == '2')
		{
			data->sprite[data->sprites_count].x = (double)data->chars + 0.5;
			data->sprite[data->sprites_count].y = (double)data->array + 0.5;
			data->map.array_map[data->array]
			[data->chars] = data->map.map[i] - 48;
			data->chars++;
			data->sprites_count++;
		}
		else if (data->map.map[i] >= '0' && data->map.map[i] <= '2')
		{
			data->map.array_map[data->array]
			[data->chars] = data->map.map[i] - 48;
			data->chars++;
		}
		i++;
	}
	return (0);
}

int		make_int_array(t_data *data)
{
	int i;

	i = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == ' ')
			data->map.map[i] = '0';
		i++;
	}
	i = 0;
	save_map_width_height(data);
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '2')
			data->sprites.num_sprite++;
		i++;
	}
	data->sprite = malloc(data->sprites.num_sprite * sizeof(t_sprite));
	save_int_array(data);
	return (0);
}
