/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/05 10:39:35 by liz           #+#    #+#                 */
/*   Updated: 2020/05/21 10:50:16 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int which_texture(t_data *data)
{
	int no;
	int so;
	int we;
	int ea;

	no = 0;
	so = 1;
	we = 2;
	ea = 3;
	if (data->ray.map_x <= data->ray.pos_x)
	{
		if (data->ray.side == 0)
			data->tex.tex_num = 0;
		if (data->ray.pos_y < data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = ea;
		else if (data->ray.pos_y > data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = we;
	}
	else if (data->ray.map_x > data->ray.pos_x)
	{
		if (data->ray.side == 0)
			data->tex.tex_num = so;
		if (data->ray.pos_y < data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = ea;
		else if (data->ray.pos_y > data->ray.map_y && data->ray.side == 1)
			data->tex.tex_num = we;
	}
		// printf("tex_num == %d\n\n", data->tex.tex_num);

}
int 	textures_make(t_data *data)
{
	// if (data->ray.map_y < data->ray.pos_y && data->ray.map_x < data->ray.pos_x)
	// 	data->tex.tex_num = 0;
	// else if (data->ray.map_y > data->ray.pos_y && data->ray.map_x > data->ray.pos_x)
	// 	data->tex.tex_num = 1;
	// else if (data->ray.map_x < data->ray.pos_x && data->ray.map_y < data->ray.pos_x)
	// 	data->tex.tex_num = 2;
	// else if (data->ray.map_x > data->ray.pos_x && data->ray.map_y > data->ray.pos_y)
	// 	data->tex.tex_num = 3;
	// if ()
	// data->tex.tex_num = data->map.array_map_int[data->ray.map_x][data->ray.map_y] - 1;
	// printf("x = %d | mapX = %d | mapY = %d || posX = %f | posY = %f | stepX = %d | stepY = %d\n", data->ray.x_ray, data->ray.map_x, data->ray.map_y, data->ray.pos_x, data->ray.pos_y, data->ray.step_x, data->ray.step_y);

		if (data->ray.side == 0)
			data->tex.wall_x = data->ray.pos_y + data->ray.perp_wall_dist * data->ray.ray_dir_y;
		else
			data->tex.wall_x = data->ray.pos_x + data->ray.perp_wall_dist * data->ray.ray_dir_x;
		data->tex.wall_x -= floor((data->tex.wall_x));

		//x coordinate on the texture
		data->tex.tex_x = (int)(data->tex.wall_x * (double)(data->textures[data->tex.tex_num].tex_width));

		if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
			data->tex.tex_x = data->textures[data->tex.tex_num].tex_width - data->tex.tex_x -1;
		if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
			data->tex.tex_x = data->textures[data->tex.tex_num].tex_width - data->tex.tex_x -1;

		//how much to increase the texture coordinate per screen pixel
		data->tex.step = 1.0 * data->textures[data->tex.tex_num].tex_height / data->ray.line_height;
		data->tex.tex_pos = (data->ray.draw_start - data->height / 2 + data->ray.line_height / 2) * data->tex.step;

		int y;
		int i = 0;
		y = data->ray.draw_start;
		while (i < data->ray.draw_start)
		{
			my_mlx_pixel_put(data, data->ray.x_ray, i,data->map.color);
			i++;
		}
		// data->tex.tex_pos = 0;
		while (y < data->ray.draw_end)
		{
			// Cast the texture coordinate to integer, and mask with (data->textures[data->tex.tex_num].tex_height - 1) in case of overflow
			data->tex.tex_y = (int)data->tex.tex_pos & (data->textures[data->tex.tex_num].tex_height - 1);
			data->tex.tex_pos += data->tex.step;
								// printf("%d | %d || %f | %f\n", data->ray.map_x, data->ray.map_y, data->ray.pos_x, data->ray.pos_y);

			int color = (data->textures[data->tex.tex_num].texture_adrr[data->textures[data->tex.tex_num].tex_height * data->tex.tex_y + data->tex.tex_x]);
			if (data->ray.side == 1)
			{
				color = add_shade(0.4, color);
			}
			my_mlx_pixel_put(data, data->ray.x_ray, y, color);
			y++;
		}
			// printf("%f | %f |%d | %d | %d | %d\n", data->tex.step, data->tex.tex_pos, y, data->tex.tex_y, data->tex.texX, data->ray.x_ray);
		while (y < data->height)
		{
			my_mlx_pixel_put(data, data->ray.x_ray, y, data->map.floor_color);
			y++;
		}
		int x = 0;
		y = 0;
		// while (y < data->height)
		// {
		// 	while (x < data->width)
		// 	{
		// 		data->textures.buffer[y][x] = 0;
		// 		x++;
		// 	}
		// 	y++;
		// }
}