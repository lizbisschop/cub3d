/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 16:23:32 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/25 17:13:46 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_program_please("Window has been closed. Goodbye!!\n");
	if (keycode == W_KEY && data->move.s != 1)
		data->move.w = 1;
	if (keycode == S_KEY && data->move.w != 1)
		data->move.s = 1;
	if (keycode == D_KEY && data->move.a != 1)
		data->move.d = 1;
	if (keycode == A_KEY && data->move.d != 1)
		data->move.a = 1;
	if (keycode == ROTATE_LEFT && data->move.r != 1)
		data->move.l = 1;
	if (keycode == ROTATE_RIGHT && data->move.l != 1)
		data->move.r = 1;
	return (0);
}
