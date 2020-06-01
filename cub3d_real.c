/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_real.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:13:35 by liz           #+#    #+#                 */
/*   Updated: 2020/05/29 13:59:13 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	get_all_data(&data, argv);
	while (i < 5)
	{
		data.textures[i].texture_adrr =
		(int *)mlx_get_data_addr(data.textures[i].tex,
		&data.textures[i].bits_per_pixel, &data.textures[i].line_length,
		&data.textures[i].endian);
		i++;
	}
	raycasting(&data);
	mlx_loop_hook(data.mlx.mlx, main_loop, &data);
	mlx_hook(data.mlx.mlx_win, 2, 1l << 0, key_input, &data);
	mlx_hook(data.mlx.mlx_win, 3, 1l << 1, key_release, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1l << 17, key_input, &data);
	mlx_loop(data.mlx.mlx);
}
