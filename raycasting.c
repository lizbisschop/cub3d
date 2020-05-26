/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 11:22:49 by liz           #+#    #+#                 */
/*   Updated: 2020/05/25 14:00:34 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	what_to_draw(t_data *data)
{
	if (data->ray.side == 0)
			data->ray.perp_wall_dist = (data->ray.map_x - data->ray.pos_x+ (1 - data->ray.step_x) / 2) / data->ray.ray_dir_x;
		else
			data->ray.perp_wall_dist = (data->ray.map_y - data->ray.pos_y + (1 - data->ray.step_y) / 2) / data->ray.ray_dir_y;

		data->ray.line_height =(int)(data->height / data->ray.perp_wall_dist);

		data->ray.draw_start = -data->ray.line_height / 2 + data->height / 2;
		if (data->ray.draw_start < 0)
			data->ray.draw_start = 0;
		data->ray.draw_end = data->ray.line_height / 2 + data->height / 2;
		if (data->ray.draw_end >= data->height)
			data->ray.draw_end = data->height - 1;
		
		// printf("%d|  %d|  %d| %d|\n", data->ray.x_ray, data->map.array_map_int[data->ray.map_x][data->ray.map_y], data->ray.draw_start, data->ray.draw_end);
		// int r, g, b, rv,gv,bv;
		// r = 255;
		// g = 0;
		// b = 0;
		// rv = 0;
		// gv = 255;
		// bv = 225;
		// if (data->map.array_map_int[data->ray.map_x][data->ray.map_y] == 1)
		// 	data->ray.color_ray = create_trgb(r,g,b);
		// if (data->map.array_map_int[data->ray.map_x][data->ray.map_y] == 2)
		// 	data->ray.color_ray = create_trgb(rv, gv, bv);
		// if (data->ray.side == 1 && data->map.array_map_int[data->ray.map_x][data->ray.map_y] == 1)
		// {
		// 	data->ray.color_ray = create_trgb(r/1.2, g/1.2, b/1.2);	
		// }
		// else if (data->ray.side == 1 && data->map.array_map_int[data->ray.map_x][data->ray.map_y] == 2)
		// {
		// 	data->ray.color_ray = create_trgb(rv/1.2, gv/1.2, bv/1.2);
		// }
		textures_make(data);
		data->zbuffer[data->ray.x_ray] = data->ray.perp_wall_dist;
		// background(data, 0xFFFFFFFF);
		// draw_line(data->ray.x_ray, data->ray.draw_start, data->ray.draw_end, data->ray.color_ray, data);
		data->ray.x_ray++;
}

int 	wall_is_hit(t_data *data)
{
	while (data->ray.hit == 0)
		{
			if (data->ray.side_dist_x < data->ray.side_dist_y)
			{
				data->ray.side_dist_x += data->ray.delta_dist_x;
				data->ray.map_x += data->ray.step_x;
				data->ray.side = 0;
			}
			else
			{
				data->ray.side_dist_y += data->ray.delta_dist_y;
				data->ray.map_y += data->ray.step_y;
				data->ray.side = 1;
			}
			//check if ray had hit a wall

			if (data->map.array_map_int[data->ray.map_y][data->ray.map_x] == 1)
			{
				
				data->ray.hit = 1;
				which_texture(data);
			}
		}
			// printf("x = %d | mapX = %d | mapY = %d || posX = %f | pos_y = %f | side = %d | texNum = %d | side = %d | Hit = %d | int_of_place = %d\n", data->ray.x_ray, data->ray.map_x, data->ray.map_y, data->ray.pos_x, data->ray.pos_y, data->ray.side, data->tex.tex_num, data->ray.side, data->ray.hit, data->map.array_map_int[(int)data->ray.pos_y][(int)data->ray.pos_x]);
}

int calculating_step(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
		{
			data->ray.step_x = -1;
			data->ray.side_dist_x = (data->ray.pos_x- data->ray.map_x) * data->ray.delta_dist_x;
		}
		else
		{
			data->ray.step_x = 1;
			data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pos_x) * data->ray.delta_dist_x;
		}
		if (data->ray.ray_dir_y < 0)
		{
			data->ray.step_y = -1;
			data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y) * data->ray.delta_dist_y;
		}
		else
		{
			data->ray.step_y = 1;
			data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pos_y) * data->ray.delta_dist_y;
		}
}

int raycasting_loop(t_data *data)
{
		data->ray.camera_x = 2 * data->ray.x_ray / (double)data->width - 1; //x-coordinate in camera space
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;

		//wich box of the map we're in
		data->ray.map_x = (int)data->ray.pos_x;
		data->ray.map_y = (int)data->ray.pos_y;

		// printf("%d | %d || %f | %f\n", data->ray.map_x, data->ray.map_y, data->ray.pos_x, data->ray.pos_y);
		// printf("%lf | %d\n", data->ray.pos_x,  data->ray.map_x);

		//length of ray from current posisition to next x or y-side
		

		data->ray.hit = 0;
		// data->ray.delta_dist_x// if (data->ray.map_y < data->ray.pos_y && data->ray.map_x < data->ray.pos_x)
	// 	data->tex.texNum = 0;
	// else if (data->ray.map_y > data->ray.pos_y && data->ray.map_x > data->ray.pos_x)
	// 	data->tex.texNum = 1;
	// else if (data->ray.map_x < data->ray.pos_x&& data->ray.map_y < data->ray.pos_x)
	// 	data->tex.texNum = 2;
	// else if (data->ray.map_x > data->ray.pos_x&& data->ray.map_y > data->ray.pos_y)
	// 	data->tex.texNum = 3; = (data->ray.ray_dir_x == 0) ? 0 : ((data->ray.ray_dir_x == 0) ? 1 : fabs(1 / data->ray.ray_dir_x));
		// data->ray.delta_dist_y = (data->ray.ray_dir_y == 0) ? 0 : ((data->ray.ray_dir_y == 0) ? 1 : fabs(1 / data->ray.ray_dir_y));


		data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
		data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);

		calculating_step(data);
		wall_is_hit(data);
		what_to_draw(data);
	// printf("ray_x = %d | dirX = %lf | dirY = %lf | cameraX = %lf | rayDirX = %lf | rayDirY = %lf | lineHeight = %d | planeX = %lf | planeY = %lf |perpWallDist = %lf| hit = %d | side = %d | stepX = %d | stepY = %d | posX = %lf | pos_y = %lf\n\n\n", data->ray.x_ray, data->ray.dir_x, data->ray.dir_y, data->ray.camera_x, data->ray.ray_dir_x, data->ray.ray_dir_y, data->ray.line_height, data->ray.plane_x, data->ray.plane_y, data->ray.perp_wall_dist, data->ray.hit, data->ray.side, data->ray.step_x, data->ray.step_y, data->ray.pos_x, data->ray.pos_y);
}

int 	raycasting(t_data *data)
{
	data->ray.x_ray = 0;
	// if (data->ray.pos_x< 0)
	// 	data->ray.pos_x= 0;
	// if (data->ray.pos_x> data->width)
	// {
	// 	data->ray.pos_x= data->width;
	// 	printf("hello\n");
	// }
	// if (data->ray.pos_y < 0)
	// {
	// 	data->ray.pos_y = 0;
	// 	printf("hello\n");
	// }
	// if (data->ray.pos_y > data->height)
	// {
	// 	data->ray.pos_y = data->height;
	// 	printf("hello\n");
	// }
	while (data->ray.x_ray < data->width)
		raycasting_loop(data);
		
	sprites(data);
	// printf("%d, %d\n", data->width, data->height);
		// printf("x = %d || posX = %f | pos_y = %f | side = %d\n", data->ray.x_ray, data->ray.pos_x, data->ray.pos_y, data->ray.side);
	

	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	// printf("hello\n");
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->textures[0].tex, 100, 0);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->textures[1].tex, 200, 0);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->textures[2].tex, 300, 0);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->textures[3].tex, 400, 0);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->textures[4].tex, 500, 0);
	// mlx_hook(data->mlx.mlx_win, 2, 1l<<0, key_input, data);
}