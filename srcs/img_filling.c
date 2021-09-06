/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_filling.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:58:07 by liz           #+#    #+#                 */
/*   Updated: 2020/06/15 15:45:08 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->mlx.addr + (y * data->mlx.line_length +
	x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
