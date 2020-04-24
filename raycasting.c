/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 11:22:49 by liz           #+#    #+#                 */
/*   Updated: 2020/04/23 13:04:25 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int 	raycasting(t_data *data)
{
	data->ray.x_ray = 0;
	while (data->ray.x_ray < data->width)
	{
		double width;
		width = data->width;
		data->ray.cameraX = 2 * data->ray.x_ray / width - 1; //x-coordinate in camera space
		data->ray.rayDirX = data->ray.dirX + data->ray.planeX * data->ray.cameraX;
		data->ray.rayDirY = data->ray.dirY + data->ray.planeY * data->ray.cameraX;

		//wich box of the map we're in
	
		data->ray.mapX = data->ray.posX;
		data->ray.mapY = data->ray.posY;
		// printf("%lf | %d\n", data->ray.posX,  data->ray.mapX);

		//length of ray from current posisition to next x or y-side
		

		data->ray.hit = 0;
		// data->ray.deltaDistX = (data->ray.rayDirX == 0) ? 0 : ((data->ray.rayDirX == 0) ? 1 : abs(1 / data->ray.rayDirX));
		// data->ray.deltaDistY = (data->ray.rayDirY == 0) ? 0 : ((data->ray.rayDirY == 0) ? 1 : abs(1 / data->ray.rayDirY));

		data->ray.deltaDistX = abs(1 / data->ray.rayDirX);
		data->ray.deltaDistY = abs(1 / data->ray.rayDirY);

		if (data->ray.rayDirX < 0)
		{
			data->ray.stepX = -1;
			data->ray.sideDistX = (data->ray.posX - data->ray.mapX) * data->ray.deltaDistX;
		}
		else
		{
			data->ray.stepX = 1;
			data->ray.sideDistX = (data->ray.mapX + 1.0 - data->ray.posX) * data->ray.deltaDistX;
		}
		if (data->ray.rayDirY < 0)
		{
			data->ray.stepY = -1;
			data->ray.sideDistY = (data->ray.posY - data->ray.mapY) * data->ray.deltaDistY;
		}
		else
		{
			data->ray.stepY = 1;
			data->ray.sideDistY = (data->ray.mapY + 1.0 - data->ray.posY) * data->ray.deltaDistY;
		}


		while (data->ray.hit == 0)
		{
			if (data->ray.sideDistX < data->ray.sideDistY)
			{
				data->ray.sideDistX += data->ray.deltaDistX;
				data->ray.mapX += data->ray.stepX;
				data->ray.side = 0;
			}
			else
			{
				data->ray.sideDistY += data->ray.deltaDistY;
				data->ray.mapY += data->ray.stepY;
				data->ray.side = 1;
			}
			//check if ray had hit a wall
			if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] > 0)
				data->ray.hit = 1;
		}
		if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.mapX - data->ray.posX + (1 - data->ray.stepX / 2) / data->ray.rayDirX);
		else
			data->ray.perpWallDist = (data->ray.mapY - data->ray.posY + (1 - data->ray.stepY) / 2) / data->ray.rayDirY;
		
		int perpWallDist;
		double height = data->height;
		perpWallDist = data->ray.perpWallDist;
		data->ray.lineHeight = data->height / data->ray.perpWallDist;

		data->ray.drawStart = -data->ray.lineHeight / 2 + data->height / 2;
		if (data->ray.drawStart < 0)
			data->ray.drawStart = 0;
		data->ray.drawEnd = data->ray.lineHeight / 2 + data->height / 2;
		if (data->ray.drawEnd >= data->height)
			data->ray.drawEnd = data->height - 1;
		
		// printf("%d|  %d|  %d| %d|\n", data->ray.x_ray, data->map.array_map_int[data->ray.mapX][data->ray.mapY], data->ray.drawStart, data->ray.drawEnd);
		
		//red
		if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 1)
			data->ray.color_ray = 0xFF0000;
		//blue
		else if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 2)
			data->ray.color_ray = 0x000000FF;
		//green
		else if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 3)
			data->ray.color_ray = 0x00FFF000;
		//yellow
		else if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 4)
			data->ray.color_ray = 0xFFFFF000;
		//white
		else
			data->ray.color_ray = 0xFFFFFFFF;
		if (data->ray.side == 1)
		{
			data->ray.color_ray = data->ray.color_ray / 2;	
		}
		draw_line(data->ray.x_ray, data->ray.drawStart, data->ray.drawEnd, data->ray.color_ray, data);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
		data->ray.x_ray++;
		printf("%d\n", data->move.x);
	}

	data->ray.moveSpeed = 0.2;
	data->ray.rotSpeed = 0.2;
	mlx_hook(data->mlx.mlx_win, 2, 1l<<0, key_input, data);
}