/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/04 14:27:53 by liz           #+#    #+#                 */
/*   Updated: 2020/05/26 10:42:50 by liz           ########   odam.nl         */
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
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.no_texture, x, y);
			x = x + 64;
		}
		x = 0;
		y = y + 64;
	}
}