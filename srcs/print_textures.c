/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/04 14:27:53 by liz           #+#    #+#                 */
/*   Updated: 2020/04/04 14:31:03 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_textures(t_data *data)
{
	int x = 0;
	int y = 0;
	while (y <= data->height)
	{
		while (x <= data->width)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_ptr, x, y);
			x = x + 64;
		}
		x = 0;
		y = y + 64;
	}
}