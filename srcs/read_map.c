/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 11:36:25 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 17:34:25 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*add_newline(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!new_str)
		exit_program_please("Error\nMalloc has failed!!");
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\n';
	new_str[i + 1] = '\0';
	return (new_str);
}

int		map_part_found(t_data *data, char **tmp, char *line)
{
	int		length;
	char	*line_2;

	if (ft_strlen(data->map.old_line) == 0 && data->map.old_line
	!= NULL && ft_strnstr(line, "1", ft_strlen(line)) && ft_strnstr(line,
	"0", ft_strlen(line)) && data->map_started == 1)
		exit_program_please("Error\nMap is not vallid\n");
	if (ft_strchr(line, '1') || ft_strchr(line, '0'))
		data->map_start = 1;
	data->map_started = 1;
	length = ft_strlen(line);
	line_2 = add_newline(line);
	data->map.map = gnl_strjoin(*tmp, line_2);
	*tmp = data->map.map;
	free(line_2);
	return (0);
}

void	check_map_line(t_data *data, char *line, char **tmp)
{
	int i;

	i = 0;
	if (ft_strnstr(line, "1", ft_strlen(line))
	|| ft_strnstr(line, "0", ft_strlen(line)) || ft_strlen(line) == 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != 'N' && line[i] != 'S' &&
			line[i] != 'E' && line[i] != 'W' && ft_isalpha(line[i]) == 1)
				data->not_map_string = 1;
			i++;
		}
		if (data->not_map_string == 0)
			map_part_found(data, tmp, line);
		data->not_map_string = 0;
	}
}

void	check_identifier(t_data *data, char *line)
{
	if ((!ft_strchr(line, 'R') && !ft_strnstr(line, "NO", ft_strlen(line))
	&& !ft_strnstr(line, "SO", ft_strlen(line))
	&& !ft_strnstr(line, "EA", ft_strlen(line))
	&& !ft_strnstr(line, "WE", ft_strlen(line))
	&& !ft_strchr(line, 'F') && !ft_strchr(line, 'C')
	&& !ft_strchr(line, 'S') && ft_strlen(line) != 0) &&
	!ft_strchr(line, '1') && !ft_strchr(line, '0'))
		exit_program_please("Error\nInvallid identfier\n");
	data->map.old_line = ft_strdup(line);
	if (!data->map.old_line)
		exit_program_please("Error\nMalloc has failed!!\n");
}

void	save_map_in_array(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		gnl_count;

	gnl_count = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_program_please("Error\nMap file doesnt exist!\n");
	tmp = malloc(1);
	if (!tmp)
		exit_program_please("Error\nMalloc has failed\n");
	tmp[0] = '\0';
	while (gnl_count > 0)
	{
		gnl_count = get_next_line(fd, &line);
		check_identifier(data, line);
		if (ft_strchr(line, 'R'))
			find_width_height(data, line);
		textures(data, line);
		color(data, line);
		check_map_line(data, line, &tmp);
		free(data->map.old_line);
		free(line);
	}
}
