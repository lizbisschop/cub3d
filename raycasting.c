/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 11:22:49 by liz           #+#    #+#                 */
/*   Updated: 2020/05/11 14:37:16 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int 	what_to_draw(t_data *data)
{
	printf("hello\n");
	if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.mapX - data->ray.posX + (1 - data->ray.stepX) / 2) / data->ray.rayDirX;
		else
			data->ray.perpWallDist = (data->ray.mapY - data->ray.posY + (1 - data->ray.stepY) / 2) / data->ray.rayDirY;

		data->ray.lineHeight =(int)(data->height / data->ray.perpWallDist);

		data->ray.drawStart = -data->ray.lineHeight / 2 + data->height / 2;
		if (data->ray.drawStart < 0)
			data->ray.drawStart = 0;
		data->ray.drawEnd = data->ray.lineHeight / 2 + data->height / 2;
		if (data->ray.drawEnd >= data->height)
			data->ray.drawEnd = data->height - 1;
		
		// printf("%d|  %d|  %d| %d|\n", data->ray.x_ray, data->map.array_map_int[data->ray.mapX][data->ray.mapY], data->ray.drawStart, data->ray.drawEnd);
		int r, g, b, rv,gv,bv;
		r = 255;
		g = 0;
		b = 0;
		rv = 0;
		gv = 255;
		bv = 225;
		// if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 1)
		// 	data->ray.color_ray = create_trgb(1, r,g,b);
		// if (data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 2)
		// 	data->ray.color_ray = create_trgb(1, rv, gv, bv);
		// if (data->ray.side == 1 && data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 1)
		// {
		// 	data->ray.color_ray = create_trgb(1, r/1.2, g/1.2, b/1.2);	
		// }
		// else if (data->ray.side == 1 && data->map.array_map_int[data->ray.mapX][data->ray.mapY] == 2)
		// {
		// 	data->ray.color_ray = create_trgb(1, rv/1.2, gv/1.2, bv/1.2);
		// }
		// ////TEXTURES TRY
		textures_make(data);
		// background(data, 0xFFFFFFFF);
		//////END OF TRY
		// draw_line(data->ray.x_ray, data->ray.drawStart, data->ray.drawEnd, data->ray.color_ray, data);
		data->ray.x_ray++;
}

int 	wall_is_hit(t_data *data)
{
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
}

int calculating_step(t_data *data)
{
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
}

int raycasting_loop(t_data *data)
{
		data->ray.cameraX = 2 * data->ray.x_ray / (double)data->width - 1; //x-coordinate in camera space
		data->ray.rayDirX = data->ray.dirX + data->ray.planeX * data->ray.cameraX;
		data->ray.rayDirY = data->ray.dirY + data->ray.planeY * data->ray.cameraX;

		//wich box of the map we're in
	
		data->ray.mapX = (int)data->ray.posX;
		data->ray.mapY = (int)data->ray.posY;
		// printf("%lf | %d\n", data->ray.posX,  data->ray.mapX);

		//length of ray from current posisition to next x or y-side
		

		data->ray.hit = 0;
		// data->ray.deltaDistX = (data->ray.rayDirX == 0) ? 0 : ((data->ray.rayDirX == 0) ? 1 : fabs(1 / data->ray.rayDirX));
		// data->ray.deltaDistY = (data->ray.rayDirY == 0) ? 0 : ((data->ray.rayDirY == 0) ? 1 : fabs(1 / data->ray.rayDirY));


		data->ray.deltaDistX = fabs(1 / data->ray.rayDirX);
		data->ray.deltaDistY = fabs(1 / data->ray.rayDirY);

		calculating_step(data);
		wall_is_hit(data);
		what_to_draw(data);
	// printf("ray_x = %d | dirX = %lf | dirY = %lf | cameraX = %lf | rayDirX = %lf | rayDirY = %lf | lineHeight = %d | planeX = %lf | planeY = %lf |perpWallDist = %lf| hit = %d | side = %d | stepX = %d | stepY = %d | posX = %lf | posY = %lf\n\n\n", data->ray.x_ray, data->ray.dirX, data->ray.dirY, data->ray.cameraX, data->ray.rayDirX, data->ray.rayDirY, data->ray.lineHeight, data->ray.planeX, data->ray.planeY, data->ray.perpWallDist, data->ray.hit, data->ray.side, data->ray.stepX, data->ray.stepY, data->ray.posX, data->ray.posY);
}

int 	raycasting(t_data *data)
{
	
	data->ray.x_ray = 0;
	// if (data->ray.posX < 0)
	// 	data->ray.posX = 0;
	// if (data->ray.posX > data->width)
	// {
	// 	data->ray.posX = data->width;
	// 	printf("hello\n");
	// }
	// if (data->ray.posY < 0)
	// {
	// 	data->ray.posY = 0;
	// 	printf("hello\n");
	// }
	// if (data->ray.posY > data->height)
	// {
	// 	data->ray.posY = data->height;
	// 	printf("hello\n");
	// }
	while (data->ray.x_ray < data->width)
		raycasting_loop(data);
	// printf("%d, %d\n", data->width, data->height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	mlx_hook(data->mlx.mlx_win, 2, 1l<<0, key_input, data);
}