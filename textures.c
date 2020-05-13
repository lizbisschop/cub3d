/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 10:39:35 by liz           #+#    #+#                 */
/*   Updated: 2020/05/12 11:30:13 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	textures_make(t_data *data)
{
	data->tex.texNum = data->map.array_map_int[data->ray.mapX][data->ray.mapY] - 1;

		if (data->ray.side == 0)
			data->tex.wallX = data->ray.posY + data->ray.perpWallDist * data->ray.rayDirY;
		else
			data->tex.wallX = data->ray.posX + data->ray.perpWallDist * data->ray.rayDirX;
		data->tex.wallX -= floor((data->tex.wallX));

		//x coordinate on the texture
		data->tex.texX = (int)(data->tex.wallX * (double)(texWidth));

		if (data->ray.side == 0 && data->ray.rayDirX > 0)
			data->tex.texX = texWidth - data->tex.texX -1;
		if (data->ray.side == 1 && data->ray.rayDirY < 0)
			data->tex.texX = texWidth - data->tex.texX -1;

		//how much to increase the texture coordinate per screen pixel
		data->tex.step = 1.0 * texHeight / data->ray.lineHeight;
		data->tex.texPos = (data->ray.drawStart - data->height / 2 + data->ray.lineHeight) * data->tex.step;

		int y;
		int i = 0;
		y = data->ray.drawStart;
		while (i < data->ray.drawStart)
		{
			my_mlx_pixel_put(data, data->ray.x_ray, i,data->map.color);
			i++;
		}
		while (y < data->ray.drawEnd)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			data->tex.texY = (int)data->tex.texPos & (texHeight - 1);
			data->tex.texPos += data->tex.step;
			unsigned int color = (data->textures[data->tex.texNum].texture_adrr[texHeight * data->tex.texY + data->tex.texX]);
			if (data->ray.side == 1)
				color = color/2;
			// draw_line(data->ray.x_ray, data->ray.drawStart, data->ray.drawEnd, (int)color, data);
			my_mlx_pixel_put(data, data->ray.x_ray, y, color);
			y++;
		}
		while (y < data->height)
		{
			my_mlx_pixel_put(data, data->ray.x_ray, y, data->map.floor_color);
			y++;
		}
		int x = 0;
		y = 0;
		// while (y < data->height)
		// {
		// 	while (x < data->width)
		// 	{
		// 		data->textures.buffer[y][x] = 0;
		// 		x++;
		// 	}
		// 	y++;
		// }
}