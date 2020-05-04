/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 11:45:37 by liz           #+#    #+#                 */
/*   Updated: 2020/05/04 13:16:28 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_release(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	data->move.x = 0;
}

int 	key_input(int keycode, t_data *data)
{
	data->move.x = 1;
	if(keycode == ESC)
	{
		exit_program_please(data, "Window has been closed. Goodbye!\n");
	}
	//w
	if (keycode == W_KEY)
	{
		// printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
		if (data->map.array_map_int[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirX * data->ray.moveSpeed)] == 0)
			data->ray.posX += data->ray.dirX * data->ray.moveSpeed;
		if (data->map.array_map_int[(int)(data->ray.posY + data->ray.dirY * data->ray.moveSpeed)][(int)(data->ray.posX)] == 0)
			data->ray.posY += data->ray.dirY * data->ray.moveSpeed;
		// data->ray.posY = 13;
		printf("%lf | %lf\n | %d | %d\n", data->ray.posX, data->ray.posY, data->map_width, data->map_height);
		printf("%d | %d\n", data->map.array_map_int[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirX * data->ray.moveSpeed)], data->map.array_map_int[(int)(data->ray.posY + data->ray.dirY * data->ray.moveSpeed)][(int)(data->ray.posX)]);
	}
	//S
	if (keycode == S_KEY)
	{
		if(data->map.array_map_int[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirX * data->ray.moveSpeed)] == 0)
			data->ray.posX -= data->ray.dirX * data->ray.moveSpeed;
      	if(data->map.array_map_int[(int)(data->ray.posY - data->ray.dirY * data->ray.moveSpeed)][(int)(data->ray.posX)] == 0)
	  		data->ray.posY -= data->ray.dirY * data->ray.moveSpeed;
		printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
				printf("%d | %d\n", data->map.array_map_int[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirX * data->ray.moveSpeed)], data->map.array_map_int[(int)(data->ray.posY - data->ray.dirY * data->ray.moveSpeed)][(int)(data->ray.posX)]);

	}
    if (keycode == RIGHT)
    {
      data->ray.oldDirX = data->ray.dirX;
      data->ray.dirX = data->ray.dirX * cos(data->ray.rotSpeed) - data->ray.dirY * sin(data->ray.rotSpeed);
      data->ray.dirY = data->ray.oldDirX * sin(data->ray.rotSpeed) + data->ray.dirY * cos(data->ray.rotSpeed);
      data->ray.oldPlaneX = data->ray.planeX;
      data->ray.planeX = data->ray.planeX * cos(data->ray.rotSpeed) - data->ray.planeY * sin(data->ray.rotSpeed);
      data->ray.planeY = data->ray.oldPlaneX * sin(data->ray.rotSpeed) + data->ray.planeY * cos(data->ray.rotSpeed);
	  printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
	//   printf("%lf | %lf | %lf\n", data->ray.dirX, data->ray.oldDirX, data->ray.rotSpeed);
	}
    // //rotate to the left
	 if (keycode == LEFT)
    {
      //both camera direction and camera plane must be rotated
      data->ray.oldDirX = data->ray.dirX;
      data->ray.dirX = data->ray.dirX * cos(-data->ray.rotSpeed) - data->ray.dirY * sin(-data->ray.rotSpeed);
      data->ray.dirY = data->ray.oldDirX * sin(-data->ray.rotSpeed) + data->ray.dirY * cos(-data->ray.rotSpeed);
      data->ray.oldPlaneX = data->ray.planeX;
      data->ray.planeX = data->ray.planeX * cos(-data->ray.rotSpeed) - data->ray.planeY * sin(-data->ray.rotSpeed);
      data->ray.planeY = data->ray.oldPlaneX * sin(-data->ray.rotSpeed) + data->ray.planeY * cos(-data->ray.rotSpeed);
	printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
	}
	if (keycode == A_KEY)
	{
		data->ray.posX += 0.25;
		// data->ray.posY -= data->ray.dirY;
		printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
	}
	if (keycode == D_KEY)
	{
		data->ray.posX -= 0.25;
		printf("%lf | %lf\n", data->ray.posX, data->ray.posY);
	}
	raycasting(data);
}