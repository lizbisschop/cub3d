/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 11:36:25 by liz           #+#    #+#                 */
/*   Updated: 2020/05/29 14:25:19 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	make_int_array(t_data *data)
{
	int i;
	int array;
	int chars;
	int total_chars;
	int sprites;
	data->map_height = 0;
	data->map_width = 0;

	i = 0;
	array = 0;
	chars = 0;
	sprites = 0;
	total_chars = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
			data->map_height++;
			if (data->map_width > total_chars)
				total_chars = (data->map_width - 1);
			data->map_width = 0;
		}
		if (data->map.map[i] == ' ')
			i++;
		i++;
		data->map_width++;
	}
	data->map_width = total_chars;
	// printf("%d | %d\n", data->map_height, data->map_width);
	data->map.array_map_int = malloc(sizeof(int*) * data->map_height + 1);
	i = 0;
	while (i < data->map_width)
	{
		data->map.array_map_int[i] = ft_calloc(data->map_width + 1, sizeof(int));
		i++;
	}
	if (!data->map.array_map_int)
		exit_program_please(data, "Malloc has failed!\n");
	i = 0;
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '2')
			data->num_sprite++;
		i++;
	}
	 
	i = 0;
	data->sprite = malloc(data->num_sprite * sizeof(t_sprite));
	while (data->map.map[i] != '\0')
	{
		if (data->map.map[i] == '\n')
		{
			chars = 0;
			array++;
		}
		if (data->map.map[i] == 'N' || data->map.map[i] == 'S' || data->map.map[i] == 'W' || data->map.map[i] == 'E')
		{
			data->ray.type = data->map.map[i];
			data->ray.pos_x = chars;
			data->ray.pos_y = array;
			data->ray.pos_x += 0.5;
			data->ray.pos_y += 0.5;
			data->map.array_map_int[array][chars] = 0;
			chars++;
		}
		if (data->map.map[i] == ' ')
		{
			data->map.array_map_int[array][chars] = 0;
			chars++;
		}
		if (data->map.map[i] == '2')
		{
			data->sprite[sprites].x = (double)chars + 0.5;
			data->sprite[sprites].y = (double)array + 0.5;
			data->sprite[sprites].texture = 2;
			data->map.array_map_int[array][chars] = data->map.map[i] - 48;
			// printf("x = %f | y = %f\n", data->sprite[sprites].x, data->sprite[sprites].y);
			chars++;
			sprites++;
		}
		else if (data->map.map[i] >= '0' && data->map.map[i] <= '9')
		{
			data->map.array_map_int[array][chars] = data->map.map[i] - 48;
			// printf("%d\n", data->map.array_map_int[array][chars]);
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
	i = 2;
	while (line[i] == ' ')
		i++;
	data->width = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
	{
		i++;
	}
	i++;
	data->height = ft_atoi(&line[i]);
	if (data->height == 0 || data->width == 0)
		exit_program_please(data, "There is an error in the window\n");
	
}

int textures(t_data *data, char *line, char **relative_path)
{
	int i;
	static int check_NO;
	static int check_SO;
	static int check_WE;
	static int check_EA;
	i = 0;
		if (ft_strchr(line, 'N') && ft_strchr(line, 'O') && check_NO < 2)
		{
			check_NO++;
			while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
				i++;
			data->map.no_path = gnl_strdup(&line[i]);
			return (1);
		}
		else if (ft_strchr(line, 'S') && ft_strchr(line, 'O') && check_SO < 2)
		{
			while (line[i] == ' ' || line[i] == 'S' || line[i] == 'O')
				i++;
			data->map.so_path = gnl_strdup(&line[i]);
			return (1);
		}
		else if (ft_strchr(line, 'W') && ft_strchr(line, 'E') && check_WE < 2)
		{
			while (line[i] == ' ' || line[i] == 'W' || line[i] == 'E')
				i++;
			data->map.we_path = gnl_strdup(&line[i]);
			return (1);
		}
		else if (ft_strchr(line, 'E') && ft_strchr(line, 'A') && check_EA < 2)
		{
			while (line[i] == ' ' || line[i] == 'E' || line[i] == 'A')
				i++;
			data->map.ea_path = gnl_strdup(&line[i]);
			return (1);
		}
		else if (line[0] == 'S' && line[1] == ' ')
		{
			i = 2;
			while (line[i] == ' ')
				i++;
			data->map.sprite= gnl_strdup(&line[i]);
			return (1);
		}
		if (check_NO > 1 || check_SO > 1 || check_EA > 1 || check_WE > 1)
			exit_program_please(data, "Wrong map input\n");
		return (0);
}

int color(t_data *data, char *line)
{
	int i;
	static int check_F;
	int check_com_F;
	int check_double_F;
	static int check_C;
	int check_com_C;
	int check_double_C;

	check_com_F = 0;
	check_double_F = 0;
	check_com_C = 0;
	check_double_C = 0;
	i = 0;
	if (ft_strchr(line, 'F'))
		{
			check_F++;
			if (check_F > 1)
				exit_program_please(data, "Double line\n");
			while (line[i] != '\0')
			{
				
				if (ft_isalpha(line[i]) && line[i] != 'F')
					exit_program_please(data, "junk in the sentence\n");
				if (line[i] == 'F')
					check_double_F++;
				if (check_double_F > 1)
					exit_program_please(data, "Double F you weirdo\n");
				if (line[i] == ',')
					check_com_F++;
				if (check_com_F > 2)
				{
					exit_program_please(data, "to many color codes\n");
				}
				i++;
				if (line[i] >= '0' && line[i] <= '9')
				{
					if (check_com_F == 0)
						data->color.r = ft_atoi(&line[i]);
					else if (check_com_F == 1)
						data->color.g = ft_atoi(&line[i]);
					else if (check_com_F == 2)
						data->color.b = ft_atoi(&line[i]);
					while (line[i] >= '0' && line[i] <= '9')
						i++;
				}
				
			}
			data->map.floor_color = create_trgb(data->color.r, data->color.g, data->color.b);
			// print_rectangle(0, 100, 80, 80, data->floor_color, data);
			return (1);
		}
		else if (ft_strchr(line, 'C'))
		{
			check_C++;
			while (line[i] != '\0')
			{
				if (check_C > 1)
					exit_program_please(data, "Double line\n");
				if (ft_isalpha(line[i]) && line[i] != 'C')
					exit_program_please(data, "junk in the sentence\n");
				if (line[i] == 'C')
					check_double_C++;
				if (check_double_C > 1)
					exit_program_please(data, "Double C you weirdo\n");
				if (line[i] == ',')
					check_com_C++;
				if (check_com_C > 2)
					exit_program_please(data, "to many color codes\n");
				i++;
				if (line[i] >= '0' && line[i] <= '9')
				{
					if (check_com_C == 0)
						data->color.r = ft_atoi(&line[i]);
					else if (check_com_C == 1)
						data->color.g = ft_atoi(&line[i]);
					else if (check_com_C == 2)
						data->color.b = ft_atoi(&line[i]);
					while (line[i] >= '0' && line[i] <= '9')
						i++;
				}
			}
			data->map.color = create_trgb(data->color.r, data->color.g, data->color.b);
			// print_rectangle(150, 600, 80, 80, data->color, data);
			return (1);
		}
		return (0);
}

int		save_map_in_array(t_data *data, char **argv)
{
	int str_cnt = 0;
	int char_cnt = 0;

	int fd;
	char *line;
	char *relative_path;
	char *tmp;

	int	gnl_count = 1;
	fd = open(argv[1], O_RDONLY);
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
	
		if (line[0] == '1' || ft_strnstr(line, "111", ft_strlen(line)) || ft_strnstr(line, "000", ft_strlen(line)))
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
		if (!data->map.no_path || !data->map.so_path || !data->map.ea_path || !data->map.we_path || !data->map.sprite)
		{
			printf("hello\n");
			exit_program_please(data, "Malloc has failed!\n");
		}

	// printf("%s\n\n", data->map.map);
	return (str_cnt);
}