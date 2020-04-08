/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 11:36:25 by liz           #+#    #+#                 */
/*   Updated: 2020/04/08 15:13:22 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int 	save_textures(t_data *data)
// {
// 	int array = 0;
// 	int chars = 0;
// 	char *relative_path;
// 	while (array < data->str_cnt)
// 	{
// 		while (data->array_map[array][chars] != '\0')
// 		{
// 			if (data->array_map[array][0] == 'N' && data->array_map[array][chars] == 'N')
// 			{
// 				while (data->array_map[array][chars] != 't')
// 					chars++;
// 				relative_path = gnl_strdup(&data->array_map[array][chars]);
// 				data->NO_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
// 			}
// 			if (data->array_map[array][0] == 'E' && data->array_map[array][chars] == 'E')
// 			{
// 				while (data->array_map[array][chars] != 't')
// 					chars++;
// 				relative_path = gnl_strdup(&data->array_map[array][chars]);
// 				data->EA_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
// 			}
// 			if (data->array_map[array][0] == 'S' && data->array_map[array][1] == 'O' && data->array_map[array][chars] == 'S')
// 			{
// 				while (data->array_map[array][chars] != 't')
// 					chars++;
// 				relative_path = gnl_strdup(&data->array_map[array][chars]);
// 				data->SO_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
// 			}
// 			if (data->array_map[array][0] == 'W' && data->array_map[array][chars] == 'W')
// 			{
// 				while (data->array_map[array][chars] != 't')
// 					chars++;
// 				relative_path = gnl_strdup(&data->array_map[array][chars]);
// 				data->WE_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
// 			}
// 			chars++;
// 		}
// 		chars = 0;
// 		array++;
// 	}
// }

int		find_width_height(t_data *data, char *line)
{
	int i;
	
	i = 2;
	while (line[i] == ' ')
		i++;
	data->width = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i++;
	data->height = ft_atoi(&line[i]);
}

int		save_map_in_array(t_data *data)
{
	int str_cnt = 0;
	int char_cnt = 0;

	int fd;
	char *line;
	char *relative_path;
	int	gnl_count = 1;
	fd = open("map.cub", O_RDONLY);
	while (gnl_count > 0)
	{
		int i = 0;
		gnl_count = get_next_line(fd, &line);
		if (line[0] == 'R')
			find_width_height(data, line);
		else if (line[0] == 'N' && line[1] == 'O')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			relative_path = gnl_strdup(&line[i]);
			data->NO_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			relative_path = gnl_strdup(&line[i]);
			data->SO_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			relative_path = gnl_strdup(&line[i]);
			data->WE_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			relative_path = gnl_strdup(&line[i]);
			data->EA_texture = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, &data->img_height);
		}
		else if (line[0] == 'S' && line[1] == ' ')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			data->sprite == gnl_strdup(&line[i]);
		}
		else if (line[0] == 'F' && line[1] == ' ')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			data->r = ft_atoi(&line[i]);
			while (line[i] != ',')
				i++;
			i++;
			data->g = ft_atoi(&line[i]);
			while (line[i] != ',')
				i++;
			i++;
			data->b = ft_atoi(&line[i]);
			data->floor_color = create_trgb(1, data->r, data->g, data->b);
			print_rectangle(0, 100, 80, 80, data->floor_color, data);
		}
		else if (line[0] == 'C' && line[1] == ' ')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			data->r = ft_atoi(&line[i]);
			while (line[i] != ',')
				i++;
			i++;
			// printf("%d|%c\n", char_cnt, str[char_cnt]);
			data->g = ft_atoi(&line[i]);
			while (line[i] != ',')
				i++;
			i++;
			data->b = ft_atoi(&line[i]);
			data->color = create_trgb(1, data->r, data->g, data->b);
			print_rectangle(150, 600, 80, 80, data->color, data);
		}
		else
		{
			data->map = ft_strjoin("", line);
			printf("%s\n", data->map);
		}
		
		free(line);	
	}
	return (str_cnt);
}