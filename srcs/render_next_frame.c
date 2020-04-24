/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/22 16:37:59 by iboeters      #+#    #+#                 */
/*   Updated: 2020/04/09 10:29:28 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int 	wasd(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	//W
	if (keycode == W_KEY && data->yw - 1 >= 0)
		data->yw-=10;
	//A
	if (keycode == A_KEY && data->xw - 1 >= 0)
		data->xw-=10;
	//S
	if (keycode == S_KEY && data->yw + 1 + 80 <= data->height)
		data->yw+=10;
	//D
	if (keycode == D_KEY && data->xw + 1 + 80 <= data->width)
		data->xw+=10;

	print_rectangle(data->xw, data->yw, 80, 80, 0xFF0000FF, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int 	render_next_frame(t_data *data)
{
	unsigned int col;
	unsigned int t;

	t = 1;
	   data->x = data->x + 1;
    // if (data->b > 125)
    //     data->r = data->r - 1;
    // if (data->r > 125)
    //     data->b = data->b + 1;
    // if (data->b > 125)
    //     data->g = data->g + 1;
	if (data->x > data->width)
	{
		data->x = 0;
		data->y += 80;
	}
	if (data->y > data->height)
	{
		data->y = 0;
	}
	col = create_trgb(t, data->r, data->g, data->b);
	data->x++;
	background(data, 0x00000000);
	print_rectangle(data->x, data->y, 80, 80, 0xFFFFFF00, data);
	mlx_hook(data->mlx_win, 2, 1l<<0, wasd, data);
	print_rectangle(data->xw, data->yw, 80, 80, 0xFF00FFFF, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_ptr, 0, 0);
	return (0);
}