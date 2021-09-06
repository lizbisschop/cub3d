/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/22 13:31:53 by liz           #+#    #+#                 */
/*   Updated: 2020/06/24 16:27:44 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loop(t_data *data)
{
	mlx_loop_hook(data->mlx.mlx, &main_loop, data);
	mlx_hook(data->mlx.mlx_win, 17, 1l << 17, &close_screen, data);
	mlx_hook(data->mlx.mlx_win, 2, 1l << 0, &key_press, data);
	mlx_hook(data->mlx.mlx_win, 3, 1l << 1, &key_release, data);
	mlx_loop(data->mlx.mlx);
}

int		main_loop(t_data *data)
{
	if (data->move.w == 1 || data->move.a == 1 ||
	data->move.l == 1 || data->move.s == 1 ||
	data->move.d == 1 || data->move.r == 1)
	{
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
		data->mlx.img = mlx_new_image(data->mlx.mlx,
		data->width, data->height);
		data->mlx.addr = mlx_get_data_addr(data->mlx.img,
		&data->mlx.bits_per_pixel, &data->mlx.line_length,
		&data->mlx.endian);
		raycasting(data);
	}
	return (0);
}
