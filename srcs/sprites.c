/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 10:40:18 by liz           #+#    #+#                 */
/*   Updated: 2020/06/24 11:36:11 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		search_color_sprite(t_data *data, int stripe)
{
	int				y;
	unsigned int	color;
	int				d;
	int				tex_y;

	y = data->sprites.draw_start_y;
	data->sprites.tex_x = (int)(256 * (stripe -
	(-data->sprites.sprite_width / 2 + data->sprites.sprite_screen_x))
	* data->textures[4].tex_width / data->sprites.sprite_width) / 256;
	if (data->sprites.transform_y > 0 && stripe > 0 && stripe < data->width &&
	data->sprites.transform_y < data->sprites.zbuffer[stripe])
	{
		while (y < data->sprites.draw_end_y)
		{
			d = (y) * 256 - data->height * 128 +
			data->sprites.sprite_height * 128;
			tex_y = ((d * data->textures[4].tex_height) /
			data->sprites.sprite_height) / 256;
			color = data->textures[4].texture_adrr[data->textures[4].tex_width
			* tex_y + data->sprites.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(data, stripe, y, color);
			y++;
		}
	}
}

void		if_statements_sprite(t_data *data)
{
	if (data->sprites.draw_start_y < 0)
		data->sprites.draw_start_y = 0;
	data->sprites.draw_end_y = data->sprites.sprite_height
	/ 2 + data->height / 2;
	if (data->sprites.draw_end_y >= data->height)
		data->sprites.draw_end_y = data->height - 1;
	data->sprites.sprite_width = abs((int)(data->height
	/ (data->sprites.transform_y)));
	data->sprites.draw_start_x = -data->sprites.sprite_width
	/ 2 + data->sprites.sprite_screen_x;
	if (data->sprites.draw_start_x < 0)
		data->sprites.draw_start_x = 0;
	data->sprites.draw_end_x = data->sprites.sprite_width
	/ 2 + data->sprites.sprite_screen_x;
	if (data->sprites.draw_end_x >= data->width)
		data->sprites.draw_end_x = data->width - 1;
}

void		set_sprite_info(t_data *data, int i)
{
	data->sprites.sprite_x =
	data->sprite[data->sprites.sprite_order[i]].x - data->ray.pos_x;
	data->sprites.sprite_y =
	data->sprite[data->sprites.sprite_order[i]].y - data->ray.pos_y;
	data->sprites.inv_det = 1.0 / (data->ray.plane_x *
	data->ray.dir_y - data->ray.dir_x * data->ray.plane_y);
	data->sprites.transform_x = data->sprites.inv_det *
	(data->ray.dir_y * data->sprites.sprite_x
	- data->ray.dir_x * data->sprites.sprite_y);
	data->sprites.transform_y = data->sprites.inv_det *
	(-data->ray.plane_y * data->sprites.sprite_x +
	data->ray.plane_x * data->sprites.sprite_y);
	data->sprites.sprite_screen_x = (int)((data->width / 2) *
	(1 + data->sprites.transform_x / data->sprites.transform_y));
	data->sprites.sprite_height = abs((int)(data->height
	/ (data->sprites.transform_y)));
	data->sprites.draw_start_y = -data->sprites.sprite_height
	/ 2 + data->height / 2;
}

void		loop_through_sprites(t_data *data, int i)
{
	int stripe;

	set_sprite_info(data, i);
	if_statements_sprite(data);
	stripe = data->sprites.draw_start_x;
	while (stripe < data->sprites.draw_end_x)
	{
		search_color_sprite(data, stripe);
		stripe++;
	}
}

int			sprites(t_data *data)
{
	int i;

	i = 0;
	while (i < data->sprites.num_sprite)
	{
		data->sprites.sprite_order[i] = i;
		data->sprites.sprite_distance[i] =
		((data->ray.pos_x - data->sprite[i].x) *
		(data->ray.pos_x - data->sprite[i].x) +
		(data->ray.pos_y - data->sprite[i].y) *
		(data->ray.pos_y - data->sprite[i].y));
		i++;
	}
	bubble_sort(data);
	i = 0;
	while (i < data->sprites.num_sprite)
	{
		loop_through_sprites(data, i);
		i++;
	}
	return (0);
}
