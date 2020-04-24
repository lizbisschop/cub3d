/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 11:36:25 by liz           #+#    #+#                 */
/*   Updated: 2020/04/23 14:33:05 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	make_int_array(t_data *data)
{
	int i;
	int array;
	int chars;
	int total_chars;
	data->xw = 0;
	data->yw = 0;

	i = 0;
	array = 0;
	chars = 0;
	// printf("%s\n\n", data->map);
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
			data->xw++;
			total_chars = (data->yw + 1) / 2;
			data->yw = 0;
		}
		i++;
		data->yw++;
	}
	data->yw = total_chars;
	i = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
			chars = 0;
			array++;
		}
		if (data->map.map[i] == 'N')
		{
			data->ray.posX = chars;
			data->ray.posY = array;
			data->map.array_map_int[array][chars] = 0;
			chars++;
		}
		else if (data->map.map[i] >= '0' && data->map.map[i] <= '9')
		{
			data->map.array_map_int[array][chars] = ft_atoi(&data->map.map[i]);
			chars++;
		}
		i++;
	}
	// data->map.yw = total_chars;
	// printf("%d\n", data->map.xw);
	// printf("%d\n", data->map.yw);
}

int	make_char_array(t_data *data)
{
	int i;
	int array = 0;
	int chars = 0;

	i = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
		chars = 0;
		array++;
		}
		else if (data->map.map[i] != ' ')
		{
			data->map.array_map_char[array][chars] = data->map.map[i];
			chars++;
		}	
		i++;
	}
}

int		find_width_height(t_data *data, char *line)
{
	int i;
	static int check_R;
	
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == 'R')
		{
			if (line[i] == 'R')
				check_R++;
			if (check_R > 1)
				exit_program_please(data, "Wrong map input\n");
			i++;

		}
		if (ft_isalpha(line[i]) && line[i] != 'R')
			exit_program_please(data, "Wrong map input\n");
		i++;
	}
	while (line[i] == ' ')
		i++;
	data->width = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i++;
	data->height = ft_atoi(&line[i]);
}

int textures(t_data *data, char *line, char **relative_path)
{
	int i;
	i = 0;
		if (ft_strchr(line, 'N') && ft_strchr(line, 'O'))
		{
			while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
				i++;
			*relative_path = gnl_strdup(&line[i]);
			// printf("%s\n", *relative_path);
			data->map.NO_texture = mlx_xpm_file_to_image(data->mlx.mlx, *relative_path, &data->mlx.img_width, &data->mlx.img_height);
			return (1);
		}
		else if (ft_strchr(line, 'S') && ft_strchr(line, 'O'))
		{
			while (line[i] == ' ' || line[i] == 'S' || line[i] == 'O')
				i++;
			*relative_path = gnl_strdup(&line[i]);
			data->map.SO_texture = mlx_xpm_file_to_image(data->mlx.mlx, *relative_path, &data->mlx.img_width, &data->mlx.img_height);
			return (1);
		}
		else if (ft_strchr(line, 'W') && ft_strchr(line, 'E'))
		{
			while (line[i] == ' ' || line[i] == 'W' || line[i] == 'E')
				i++;
			*relative_path = gnl_strdup(&line[i]);
			data->map.WE_texture = mlx_xpm_file_to_image(data->mlx.mlx, *relative_path, &data->mlx.img_width, &data->mlx.img_height);
			return (1);
		}
		else if (ft_strchr(line, 'E') && ft_strchr(line, 'A'))
		{
			while (line[i] == ' ' || line[i] == 'E' || line[i] == 'A')
				i++;
			*relative_path = gnl_strdup(&line[i]);
			data->map.EA_texture = mlx_xpm_file_to_image(data->mlx.mlx, *relative_path, &data->mlx.img_width, &data->mlx.img_height);
			return (1);
		}
		return (0);
}

int color(t_data *data, char *line)
{
	int i;
	i = 0;
	if (ft_strchr(line, 'F'))
		{
			while (line[i] == ' ' || line[i] == 'F')
				i++;
			data->color.r = ft_atoi(&line[i]);
			while (line[i] != ',' || line[i] == ' ')
				i++;
			i++;
			data->color.g = ft_atoi(&line[i]);
			while (line[i] != ',' || line[i] == ' ')
				i++;
			i++;
			data->color.b = ft_atoi(&line[i]);
			data->map.floor_color = create_trgb(1, data->color.r, data->color.g, data->color.b);
			// print_rectangle(0, 100, 80, 80, data->floor_color, data);
			return (1);
		}
		else if (ft_strchr(line, 'C'))
		{
			while (line[i] == ' ' || line[i] == 'C')
				i++;
			data->color.r = ft_atoi(&line[i]);
			while (line[i] != ',' || line[i] == ' ')
				i++;
			i++;
			// printf("%d|%c\n", char_cnt, str[char_cnt]);
			data->color.g = ft_atoi(&line[i]);
			while (line[i] != ',' || line[i] == ' ')
				i++;
			i++;
			data->color.b = ft_atoi(&line[i]);
			data->map.color = create_trgb(1, data->color.r, data->color.g, data->color.b);
			// print_rectangle(150, 600, 80, 80, data->color, data);
			return (1);
		}
		return (0);
}

int		save_map_in_array(t_data *data)
{
	int str_cnt = 0;
	int char_cnt = 0;

	int fd;
	char *line;
	char *relative_path;
	char *tmp;

	int	gnl_count = 1;
	fd = open("./maps/map_1.cub", O_RDONLY);
	tmp = malloc(1);
	tmp[0] = '\0';
	while (gnl_count > 0)
	{

		int i = 0;
		gnl_count = get_next_line(fd, &line);
		if (ft_strchr(line, 'R'))
		{
			find_width_height(data, line);
		}
		textures(data, line, &relative_path);
		color(data, line);
		if (line[0] == 'S' && line[1] == ' ')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			data->map.sprite == gnl_strdup(&line[i]);
		}
		else if (line[0] >= '0' && line[0] <= '9')
		{
			int i = 0;
			int length = ft_strlen(line);
			line[length] = '\n';
			line[length + 1] = '\0';
			data->map.map = gnl_strjoin(tmp, line);
			tmp = data->map.map;
		}
		free(line);	
	}
	return (str_cnt);
}