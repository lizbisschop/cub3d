/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_try.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 17:37:36 by liz           #+#    #+#                 */
/*   Updated: 2020/04/08 15:21:37 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
// #include <vector>
// #include <iostream>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int 	background(t_data *data, int col)
{
	int x = 0;
	int y = 0;

	while (y < data->height)
	{
		while (x < data->width)
		{
			my_mlx_pixel_put(data, x, y, col);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int 	draw_line(int x, int drawStart, int drawEnd, int color, t_data *data)
{
	int y = drawStart;

	while (y <= drawEnd)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int 	wasd(int keycode, t_data *data)
{
	//W
	if (keycode == W_KEY)
	{
		if (worldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX += data->dirX * data->moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)])
			data->posY += data->dirY * data->moveSpeed;
	}
	//S
	if (keycode == S_KEY)
	{
		if(worldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX -= data->dirX * data->moveSpeed;
      if(worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)])
	  	data->posY -= data->dirY * data->moveSpeed;
	}
	 if (keycode == A_KEY)
    {
      //both camera direction and camera plane must be rotated
      data->oldDirX = data->dirX;
      data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
      data->dirY = data->oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
      data->oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
      data->planeY = data->oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
    }
    //rotate to the left
    if (keycode == D_KEY)
    {
      //both camera direction and camera plane must be rotated
      data->oldDirX = data->dirX;
      data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
      data->dirY = data->oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
      data->oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
      data->planeY = data->oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
    }
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int 	render_next_frame(t_data *data)
{
	while (data->x < data->width)
	{
		data->cameraX = 2 * data->x / data->width - 1; //x-coordinate in camera space
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;

		//wich box of the map we're in
		data->mapX = data->posX;
		data->mapY = data->posY;

		//length of ray from current posisition to next x or y-side
		

		data->hit = 0;
		data->deltaDistX = (data->rayDirX == 0) ? 0 : ((data->rayDirX == 0) ? 1 : abs(1 / data->rayDirX));
		data->deltaDistY = (data->rayDirY == 0) ? 0 : ((data->rayDirY == 0) ? 1 : abs(1 / data->rayDirY));

		if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
		while (data->hit == 0)
		{
			if (data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = 0;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = 0;
			}
			//check if ray had hit a wall
			if (worldMap[data->mapX][data->mapY] > 0)
				data->hit = 1;
		}
		if (data->side == 0)
			data->perpWallDist = (data->mapX - data->posX + (1 - data->stepX / 2) / data->rayDirX);
		else
			data->perpWallDist = (data->mapY - data->posY + (1 - data->stepY) / 2) / data->rayDirY;
		data->lineHeight = data->height / data->perpWallDist;

		data->drawStart = -data->lineHeight / 2 + data->height / 2;
		if (data->drawStart < 0)
			data->drawStart = 0;
		data->drawEnd = data->lineHeight / 2 + data->height / 2;
		if (data->drawEnd >= data->height)
			data->drawEnd = data->height - 1;
		data->color = 0xFFFF0000;
		if (data->side == 1)
			data->color = data->color / 2;	
		draw_line(data->x, data->drawStart, data->drawEnd, data->color, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
		printf("%d\n", data->lineHeight);
	}

	// data->oldTime = data->time;
	// data->time = GetTickCount();
	// data->frameTime = (data->time - data->oldTime) / 1000.0;
	// background(data, 0xFFFFFFFF);

	// data->moveSpeed = data->frameTime * 5.0;
	// data->rotSpeed = data->frameTime * 3.0;
	// mlx_hook(data->mlx_win, 2, 1l<<0, wasd, data);
}


int		main(void)
{
	t_data data;
	

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1010, 700, "CUB3D");
	data.img = mlx_new_image(data.mlx, 1010, 700);
	data.width = 1010;
	data.height = 700;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	// map_int_array(&data);
	data.str_cnt = save_map_in_array(&data);

	//RAYCASTING??
	data.posX = 22;
	data.posY = 12;
	data.planeX = 0;
	data.planeY = 0.66;
	data.time = 0;
	data.oldTime = 0;
	data.x = 0;
	// mlx_loop_hook(data.mlx ,render_next_frame, &data);

	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 300, 300);
	printf("%d|%d\n", data.floor_color, data.color);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.EA_texture, 0, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.SO_texture, 500, 500);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.WE_texture, 100, 100);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.NO_texture, 200, 200);
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.sprite, 0, 0);

	mlx_loop(data.mlx);
}
