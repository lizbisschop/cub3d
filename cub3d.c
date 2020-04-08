/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 19:18:45 by liz           #+#    #+#                 */
/*   Updated: 2020/04/07 15:01:29 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}



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

void	get_col(t_data *data)
{
	int i = 0;
	int char_cnt = 0;
	char *str;
	while (i < data->str_cnt)
	{
		if (data->array_map[i][0] == 'C')
		{
			str = ft_strdup(data->array_map[i]);
			// printf("%s\n", str);
			while (str[char_cnt] < '0' || str[char_cnt] > '9')
				char_cnt++;
			data->r = ft_atoi(&str[char_cnt]);
			while (str[char_cnt] != ',')
				char_cnt++;
			char_cnt++;
			// printf("%d|%c\n", char_cnt, str[char_cnt]);
			data->g = ft_atoi(&str[char_cnt]);
			while (str[char_cnt] != ',')
				char_cnt++;
			char_cnt++;
			data->b = ft_atoi(&str[char_cnt]);
			// printf("%d|%d|%d\n", data->r, data->g, data->b);
		}
		i++;
	}
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
	background(data, col);
	print_rectangle(data->x, data->y, 80, 80, 0xFF00FF00, data);
	// mlx_hook(data->mlx_win, 2, 1l<<0, wasd, data);
	print_rectangle(data->xw, data->yw, 80, 80, 0xFF0000FF, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_ptr, 0, 0);
	return (0);
}

int             main(void)
{
	t_data		img;
	int biggest = 200;
	int x_begin = 100;
	img.width = 1010;
	img.height = 700;
	// img.str_cnt = read_map(&img);
	// get_col(&img);
	img.x = 0;
	img.y = 0;
	
	img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 1010, 700, "CUB3D");
    img.img = mlx_new_image(img.mlx, 1010, 700);
	img.img_ptr = mlx_xpm_file_to_image(img.mlx, "./teapot.xpm", &img.img_width, &img.img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	

	img.xw = 200;
	img.yw = 200;
	// print_rectangle(img.xw, img.yw, 80, 80, 0xFFFF00FF, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_hook(img.mlx_win, 2, 1l<<0, close, &img);
	// img.img_ptr = mlx_xpm_file_to_image(img.mlx, "./wall_1.xpm", &img.img_width, &img.img_height);
	// print_map(&img);
	// hooks(&img);
	// print_textures(&img);
	// mlx_clear_window(data.mlx, data.win);
    mlx_loop(img.mlx);
}
