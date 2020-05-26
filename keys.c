/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 11:45:37 by liz           #+#    #+#                 */
/*   Updated: 2020/05/25 17:12:34 by liz           ########   odam.nl         */
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
	printf("%d\n", keycode);
	data->move.x = 1;
	if(keycode == ESC)
	{
		exit_program_please(data, "Window has been closed. Goodbye!\n");
	}
	//w
	if (keycode == W_KEY)
	{
		// printf("%lf | %lf\n", data->ray.pos_x, data->ray.pos_y);
		if (data->map.array_map_int[(int)(data->ray.pos_y)][(int)(data->ray.pos_x + data->ray.dir_x * data->ray.move_speed)] != 1)
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)][(int)(data->ray.pos_x)] != 1)
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
		// data->ray.pos_y = 13;
		printf("%lf | %lf\n", data->ray.pos_x, data->ray.pos_y);
	}
	//S
	if (keycode == S_KEY)
	{
		if(data->map.array_map_int[(int)(data->ray.pos_y)][(int)(data->ray.pos_x - data->ray.dir_x * data->ray.move_speed)] != 1)
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
      	if(data->map.array_map_int[(int)(data->ray.pos_y - data->ray.dir_y * data->ray.move_speed)][(int)(data->ray.pos_x)] != 1)
	  		data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
		printf("pos x = %lf | pos y = %lf\n", data->ray.pos_x, data->ray.pos_y);

	}
    if (keycode == ROTATE_RIGHT)
    {
	//   printf("%lf | %lf | %lf\n", data->ray.dir_x, data->ray.old_dir_x, data->ray.rot_speed);
      data->ray.old_dir_x = data->ray.dir_x;
      data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed) - data->ray.dir_y * sin(-data->ray.rot_speed);
      data->ray.dir_y = data->ray.old_dir_x * sin(-data->ray.rot_speed) + data->ray.dir_y * cos(-data->ray.rot_speed);
      data->ray.old_plane_x = data->ray.plane_x;
      data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed) - data->ray.plane_y * sin(-data->ray.rot_speed);
      data->ray.plane_y = data->ray.old_plane_x * sin(-data->ray.rot_speed) + data->ray.plane_y * cos(-data->ray.rot_speed);
	  printf("pos x = %lf | pos y = %lf\n", data->ray.pos_x, data->ray.pos_y);

	}
    // //rotate to the left
	 if (keycode == ROTATE_LEFT)
    {
      data->ray.old_dir_x = data->ray.dir_x;
      data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed) - data->ray.dir_y * sin(data->ray.rot_speed);
      data->ray.dir_y = data->ray.old_dir_x * sin(data->ray.rot_speed) + data->ray.dir_y * cos(data->ray.rot_speed);
      data->ray.old_plane_x = data->ray.plane_x;
      data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed) - data->ray.plane_y * sin(data->ray.rot_speed);
      data->ray.plane_y = data->ray.old_plane_x * sin(data->ray.rot_speed) + data->ray.plane_y * cos(data->ray.rot_speed);
		printf("pos x = %lf | pos y = %lf\n", data->ray.pos_x, data->ray.pos_y);
      //both camera direction and camera plane must be rotated
	}
	if (keycode == A_KEY)
	{
		if (data->map.array_map_int[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x - data->ray.plane_x
			* data->ray.move_speed)] == 0)
			data->ray.pos_x -= data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y
			- data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] == 0)
			data->ray.pos_y -= data->ray.plane_y
			* data->ray.move_speed;
}
	if (keycode == D_KEY)
	{	
		if (data->map.array_map_int[(int)data->ray.pos_y]
			[(int)(data->ray.pos_x + data->ray.plane_x
			* data->ray.move_speed)] == 0)
			data->ray.pos_x += data->ray.plane_x
			* data->ray.move_speed;
		if (data->map.array_map_int[(int)(data->ray.pos_y
			+ data->ray.plane_y * data->ray.move_speed)]
			[(int)data->ray.pos_x] == 0)
			data->ray.pos_y += data->ray.plane_y
			* data->ray.move_speed;
	}
	raycasting(data);
}