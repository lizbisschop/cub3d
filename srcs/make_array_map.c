/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_array_map.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 10:44:01 by liz           #+#    #+#                 */
/*   Updated: 2020/06/04 13:35:59 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		malloc_array_map(t_data *data)
{
	int i;

	i = 0;
	data->map.array_map_int = malloc(sizeof(int*) * data->map_height + 1);
	while (i < data->map_width)
	{
		data->map.array_map_int[i] =
		ft_calloc(data->map_width + 1, sizeof(int));
		i++;
	}
	if (!data->map.array_map_int)
		exit_program_please(data, "Malloc has failed!\n");
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
		data->ray.type = data->map.map[i];
		data->ray.pos_x = (double)data->chars + 0.5;
		data->ray.pos_y = (double)data->array + 0.5;
		data->map.array_map_int[data->array][data->chars] = 0;
		data->chars++;
	}
	if (data->map.map[i] == ' ')
	{
		data->map.array_map_int[data->array][data->chars] = 0;
		data->chars++;
	}
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
			data->sprite[data->sprites].x = (double)data->chars + 0.5;
			data->sprite[data->sprites].y = (double)data->array + 0.5;
			data->sprite[data->sprites].texture = 2;
			data->map.array_map_int[data->array]
			[data->chars] = data->map.map[i] - 48;
			data->chars++;
			data->sprites++;
		}
		else if (data->map.map[i] >= '0' && data->map.map[i] <= '9')
		{
			data->map.array_map_int[data->array]
			[data->chars] = data->map.map[i] - 48;
			data->chars++;
		}
		i++;
	}
}

int		make_int_array(t_data *data)
{
	int i;

	i = 0;
	save_map_width_height(data);
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '2')
			data->num_sprite++;
		i++;
	}
	data->sprite = malloc(data->num_sprite * sizeof(t_sprite));
	save_int_array(data);
}
