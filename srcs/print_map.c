/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/04 15:54:19 by liz           #+#    #+#                 */
/*   Updated: 2020/04/08 15:10:15 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	print_map(t_data *data)
// {
// 	int count_array = 0;
// 	int count_char = 0;

// 	while (count_array < data->str_cnt)
// 	{
// 		while(data->array_map[count_array][count_char] != '\0')
// 		{
// 			if (data->array_map[count_array][count_char] == '0')
// 			{
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_ptr, 0, 0);
// 			}
// 			else if (data->array_map[count_array][count_char] == '1')
// 			{
// 				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 			}
// 			count_char++;
// 		}
// 		count_array++;
// 	}
// }