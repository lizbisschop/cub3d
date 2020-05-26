/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_real.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:13:35 by liz           #+#    #+#                 */
/*   Updated: 2020/05/26 11:28:09 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int		main(int argc, char **argv)
{
	t_data data;
	
	get_all_data(&data, argv);
	int i = 0;
	while (i < 5)
	{
		// printf("hello\n");
		data.textures[i].texture_adrr = (int *)mlx_get_data_addr(data.textures[i].tex, &data.textures[i].bits_per_pixel, &data.textures[i].line_length, &data.textures[i].endian);
		i++;
	}
	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.textures[4].tex, 0, 0);
	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.mlx.img, 0, 0);

	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.textures[1].tex, 0, 0);
	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.map.SO_texture, 500, 500);
	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.map.WE_texture, 100, 100);
	// mlx_put_image_to_window(data.mlx.mlx, data.mlx.mlx_win, data.map.NO_texture, 200, 200);
	raycasting(&data);
	mlx_loop_hook(data.mlx.mlx, main_loop, &data);
	mlx_hook(data.mlx.mlx_win, 2, 1l<<0, key_input, &data);
	mlx_hook(data.mlx.mlx_win, 3, 1l<<1, key_release, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1l<<17, key_input, &data);
	// printf("hello\n");
	mlx_loop(data.mlx.mlx);
}