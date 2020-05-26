/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 10:40:18 by liz           #+#    #+#                 */
/*   Updated: 2020/05/26 11:30:15 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_sprite_visible(t_data *data, int color, int i)
{
	int count;
	int hit;

	hit = 0;
	count = data->sprite[i].x;
	while (count < data->ray.pos_x)
	{
		if (data->map.array_map_int[(int)data->sprite[i].y][count] == 1)
		{
			hit = 1;
		}
		count++;
	}
	while (count > data->ray.pos_x)
	{
		if (data->map.array_map_int[(int)data->sprite[i].y][count] == 1)
			hit = 1;
		count--;
	}
	return (hit);
}

void sort_sprites(int* order, double* dist, int amount)
{
	int i;
	int d;
	int swap;

	i = 0;
	d = 0;
	while (i < amount - 1)
	{
		while (d < amount - i - 1)
		{
			if (dist[i] > dist[i + 1])
			{
				swap = dist[i];
				dist[i] = dist[i + 1];
				dist[i + 1] = swap;
			}
			d++;
		}
		i++;
	}
	for (int c = 0; c < amount; c++)
	{
		// printf("distance = %f\n", dist[c]);
	}
}

int 	sprites(t_data *data)
{
	int i;
	int hit;

	i = 0;
	while (i < num_sprites)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->ray.pos_x - data->sprite[i].x) * (data->ray.pos_x - data->sprite[i].x) + (data->ray.pos_y - data->sprite[i].y) * data->ray.pos_y - data->sprite[i].y);
		// printf("%d | %f\n", data->sprite_order[i], data->sprite_distance[i]);
		i++;
	}
	sort_sprites(data->sprite_order, data->sprite_distance, num_sprites);

	i = 0;
	while (i < num_sprites)
	{
		data->sprite_x = data->sprite[data->sprite_order[i]].x - data->ray.pos_x;
		data->sprite_y = data->sprite[data->sprite_order[i]].y - data->ray.pos_y;

	data->inv_det = 1.0 / (data->ray.plane_x * data->ray.dir_y - data->ray.plane_y * data->ray.dir_x);
	// printf("%f\n", data->inv_det);

	data->transform_x = data->inv_det * (data->ray.dir_y * data->sprite_x - data->ray.dir_x  * data->sprite_y);
	data->transform_y = data->inv_det * (-data->ray.plane_y * data->sprite_x + data->ray.plane_x * data->sprite_y);

	data->sprite_screen_x = (int)((data->width / 2) * (1 + data->transform_x / data->transform_y));

	data->sprite_height = abs((int)(data->height / (data->transform_y)));
	data->draw_start_y = -data->sprite_height / 2 + data->height / 2;
      if(data->draw_start_y < 0) 
	  	data->draw_start_y = 0;
    data->draw_end_y = data->sprite_height / 2 + data->height / 2;
      if(data->draw_end_y >= data->height) 
	  	data->draw_end_y = data->height - 1;

      //calculate width of the sprite
      data->sprite_width = abs((int)(data->height / (data->transform_y)));
      data->draw_start_x = -data->sprite_width / 2 + data->sprite_screen_x;
      if(data->draw_start_x < 0) 
	  	data->draw_start_x = 0;
      data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
      if(data->draw_end_x >= data->width)
		data->draw_end_x = data->width - 1;
	// printf("%d | %d\n", data->draw_start_x, data->draw_end_x);
	int stripe = data->draw_start_x;
	// printf("\nsp %i\t|sp_dist %.3f|sp_x %.3f|sp_y %.3f|inv %.3f|tr_x %.3f|tr_y %.3f|sp_sc_x %i|sp_he %i|sp_wi %i|dr_s_x %i|dr_e_x %i|dr_s_y %i|dr_e_y %i|", data->sprite_order[i], data->sprite_distance[i], data->sprite_x, data->sprite_y, data->inv_det, data->transform_x, data->transform_y, data->sprite_screen_x, data->sprite_height, data->sprite_width, data->draw_start_x, data->draw_end_x, data->draw_start_y, data->draw_end_y);
		// printf("posx = %f | posy = %f | sprite_x = %f | sprite_y = %f\n", data->ray.pos_x, data->ray.pos_y, data->sprite[i].x, data->sprite[i].y);

	while (stripe < data->draw_end_x)
	{
		int y = data->draw_start_y;
		int tex_x = (int)(256 * (stripe - (-data->sprite_width / 2 + data->sprite_screen_x)) * texWidth / data->sprite_width) / 256;
		// printf("%f\n", data->transform_y);
			// printf(" zbuffer = %f\n", data->zbuffer[stripe]);	
		if(data->transform_y > 0 && stripe > 0 && stripe < data->width && data->transform_y < data->zbuffer[stripe]) // check if statement!!!!
		{
			// printf("%f||||||||\n", data->transform_y);	// printf(" %f |%f\n", data->transform_y, data->zbuffer[stripe]);
					// printf("%d\t", tex_x);
			while (y < data->draw_end_y)
			{
					// printf("%d\n", i);
				int d = (y) * 256 - data->height * 128 + data->sprite_height * 128;
				int tex_y = ((d * texHeight) / data->sprite_height) / 256;
				unsigned int color = data->textures[4].texture_adrr[texWidth * tex_y + tex_x];
				// printf("%u\n", color);
				hit = is_sprite_visible(data, color, i);
				if ((color & 0x00FFFFFF) != 0 && hit != 1)
				{
					my_mlx_pixel_put(data, stripe, y, color); 
				}
				y++;
			}
		}
		stripe++;
	}
		i++;
	}
		// printf("\n");

}