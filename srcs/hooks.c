/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 19:16:38 by liz           #+#    #+#                 */
/*   Updated: 2020/04/21 16:30:27 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int 	red_cross(int button, t_data *data)
{
	printf("%d\n", button);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
}

int             close_window(int keycode, t_data *data)
{
	// mlx_mouse_hook(data->mlx.win, mouse_movement, data);
	if (keycode == ESC)
	{
    	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		exit_program_please(data, "The window was closed. Goodbye\n");
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
	mlx_hook(data->mlx.mlx_win, 2, 1l<<0, close, data);
	// mlx_hook(data->mlx.mlx, 7, 1l<<4, mouse_enter, data);
	// mlx_hook(data->mlx.mlx, 8, 1l<<5, mouse_leave, data);
}
