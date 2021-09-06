/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 13:39:13 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 16:54:22 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	no_so(t_data *data, char *line)
{
	int			i;
	static int	check_no;
	static int	check_so;

	i = 0;
	if (ft_strchr(line, 'N') && ft_strchr(line, 'O') && check_no < 2)
	{
		check_no++;
		while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
			i++;
		data->map.no_path = ft_strdup(&line[i]);
		if (data->map_start == 1)
			exit_program_please("Error\nNO after map!\n");
	}
	else if (ft_strchr(line, 'S') && ft_strchr(line, 'O') && check_so < 2)
	{
		check_so++;
		while (line[i] == ' ' || line[i] == 'S' || line[i] == 'O')
			i++;
		data->map.so_path = ft_strdup(&line[i]);
		if (data->map_start == 1)
			exit_program_please("Error\nSO after map!\n");
	}
	if (check_no > 1 || check_so > 1)
		exit_program_please("Error\nWrong map input\n");
}

void	we_ea(t_data *data, char *line)
{
	static int	check_we;
	static int	check_ea;
	int			i;

	i = 0;
	if (ft_strchr(line, 'W') && ft_strchr(line, 'E') && check_we < 2)
	{
		check_we++;
		while (line[i] == ' ' || line[i] == 'W' || line[i] == 'E')
			i++;
		data->map.we_path = ft_strdup(&line[i]);
		if (data->map_start == 1)
			exit_program_please("Error\nWE after map!\n");
	}
	else if (ft_strchr(line, 'E') && ft_strchr(line, 'A') && check_ea < 2)
	{
		check_ea++;
		while (line[i] == ' ' || line[i] == 'E' || line[i] == 'A')
			i++;
		data->map.ea_path = ft_strdup(&line[i]);
		if (data->map_start == 1)
			exit_program_please("Error\nR after map!\n");
	}
	if (check_we > 1 || check_ea > 1)
		exit_program_please("Error\nWrong map input\n");
}

int		textures(t_data *data, char *line)
{
	int			i;
	static int	check_sprites;

	i = 0;
	no_so(data, line);
	we_ea(data, line);
	if (line[0] == 'S' && line[1] == ' ')
	{
		check_sprites++;
		i = 2;
		while (line[i] == ' ')
			i++;
		data->map.sprite = ft_strdup(&line[i]);
		if (data->map_start == 1)
			exit_program_please("Error\nS after map!\n");
	}
	if (check_sprites > 1)
		exit_program_please("Error\nWrong map input\n");
	return (0);
}
