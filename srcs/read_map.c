/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 11:36:25 by liz           #+#    #+#                 */
/*   Updated: 2020/06/05 13:57:53 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		map_part_found(t_data *data, char **tmp, char *line)
{
	int i;
	int length;

	length = ft_strlen(line);
	i = 0;
	line[length] = '\n';
	line[length + 1] = '\0';
	data->map.map = gnl_strjoin(*tmp, line);
	*tmp = data->map.map;
	return (0);
}

int		save_map_in_array(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		gnl_count;
	int		i;

	gnl_count = 1;
	fd = open("./maps/map_1.cub", O_RDONLY);
	if (fd == -1)
		exit_program_please(data, "Map file doesnt exist!\n");
	tmp = malloc(1);
	tmp[0] = '\0';
	while (gnl_count > 0)
	{
		i = 0;
		gnl_count = get_next_line(fd, &line);
		if (ft_strchr(line, 'R'))
			find_width_height(data, line);
		textures(data, line);
		color(data, line);
		if (line[0] == '1' || ft_strnstr(line, "111", ft_strlen(line))
		|| ft_strnstr(line, "000", ft_strlen(line)))
			map_part_found(data, &tmp, line);
		free(line);
	}
	return (0);
}
