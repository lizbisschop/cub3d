/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 19:16:38 by liz            #+#    #+#                */
/*   Updated: 2020/04/03 13:29:24 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int 	red_cross(int button, t_data *data)
{
	printf("%d\n", button);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

int             close_window(int keycode, t_data *data)
{
	// mlx_mouse_hook(data->win, mouse_movement, data);
	if (keycode == ESC)
	{
    	mlx_destroy_window(data->mlx, data->mlx_win);
		// printf("program has quit unexpectedly\n");
	}
	else 
		printf("%d\n", keycode);
}

int 		mouse_enter(t_data *data)
{
	printf("Hello!\n");
}

int 		mouse_leave(t_data *data)
{
	printf("Bye!\n");
}

int	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1l<<0, close, data);
	// mlx_hook(data->mlx, 7, 1l<<4, mouse_enter, data);
	// mlx_hook(data->mlx, 8, 1l<<5, mouse_leave, data);
}
