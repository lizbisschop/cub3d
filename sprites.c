/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 10:40:18 by liz           #+#    #+#                 */
/*   Updated: 2020/05/29 11:48:09 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			search_color_sprite(t_data *data, int stripe)
{
	int				y;
	int				tex_x;
	unsigned int	color;
	int				d;
	int				tex_y;

	y = data->draw_start_y;
	tex_x = (int)(256 * (stripe -
	(-data->sprite_width / 2 + data->sprite_screen_x))
	* data->textures[4].tex_width / data->sprite_width) / 256;
	if (data->transform_y > 0 && stripe > 0 && stripe < data->width &&
	data->transform_y < data->zbuffer[stripe])
	{
		while (y < data->draw_end_y)
		{
			d = (y) * 256 - data->height * 128 + data->sprite_height * 128;
			tex_y = ((d * data->textures[4].tex_height) /
			data->sprite_height) / 256;
			color = data->textures[4].texture_adrr[data->textures[4].tex_width
			* tex_y + tex_x];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(data, stripe, y, color);
			y++;
		}
	}
}

int			set_sprite_info(t_data *data, int i)
{
	data->sprite_x = data->sprite[data->sprite_order[i]].x - data->ray.pos_x;
	data->sprite_y = data->sprite[data->sprite_order[i]].y - data->ray.pos_y;
	data->inv_det = 1.0 / (data->ray.plane_x *
	data->ray.dir_y - data->ray.plane_y * data->ray.dir_x);
	data->transform_x = data->inv_det *
	(data->ray.dir_y * data->sprite_x - data->ray.dir_x * data->sprite_y);
	data->transform_y = data->inv_det *
	(-data->ray.plane_y * data->sprite_x + data->ray.plane_x * data->sprite_y);
	data->sprite_screen_x = (int)((data->width / 2) *
	(1 + data->transform_x / data->transform_y));
	data->sprite_height = abs((int)(data->height / (data->transform_y)));
	data->draw_start_y = -data->sprite_height / 2 + data->height / 2;
}

int			loop_through_sprites(t_data *data, int i)
{
	int stripe;

	set_sprite_info(data, i);
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y = data->sprite_height / 2 + data->height / 2;
	if (data->draw_end_y >= data->height)
		data->draw_end_y = data->height - 1;
	data->sprite_width = abs((int)(data->height / (data->transform_y)));
	data->draw_start_x = -data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_start_x < 0)
		data->draw_start_x = 0;
	data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_end_x >= data->width)
		data->draw_end_x = data->width - 1;
	stripe = data->draw_start_x;
	while (stripe < data->draw_end_x)
	{
		search_color_sprite(data, stripe);
		stripe++;
	}
}

int			sprites(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_sprite)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->ray.pos_x - data->sprite[i].x) *
		(data->ray.pos_x - data->sprite[i].x) +
		(data->ray.pos_y - data->sprite[i].y) *
		(data->ray.pos_y - data->sprite[i].y));
		i++;
	}
	i = 0;
	bubble_sort(data);
	while (i < data->num_sprite)
	{
		loop_through_sprites(data, i);
		i++;
	}
}
