/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 11:47:40 by liz           #+#    #+#                 */
/*   Updated: 2020/06/24 11:12:30 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		swap(t_data *data, int j)
{
	int		temp_order;
	double	temp_dist;

	temp_dist = (data->sprites.sprite_distance)[j];
	temp_order = (data->sprites.sprite_order)[j];
	(data->sprites.sprite_distance)[j] = (data->sprites.sprite_distance)[j + 1];
	(data->sprites.sprite_distance)[j + 1] = temp_dist;
	(data->sprites.sprite_order)[j] = (data->sprites.sprite_order)[j + 1];
	(data->sprites.sprite_order)[j + 1] = temp_order;
}

void		bubble_sort(t_data *data)
{
	int		swapped;
	int		i;
	int		j;

	swapped = 1;
	i = 0;
	j = 0;
	while (data->sprites.num_sprite - i > 1 && swapped == 1)
	{
		swapped = 0;
		j = 0;
		while (j < data->sprites.num_sprite - i - 1)
		{
			if ((data->sprites.sprite_distance)[j]
			< (data->sprites.sprite_distance)[j + 1])
			{
				swap(data, j);
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}
