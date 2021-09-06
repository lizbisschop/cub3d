/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_color.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 14:19:04 by liz           #+#    #+#                 */
/*   Updated: 2020/06/29 17:10:12 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_color(t_data *data, char *line, int *i, int check_com_c)
{
	if (check_com_c == 0 && data->colors.r == -1)
		data->colors.r = ft_atoi(&line[*i]);
	else if (check_com_c == 1 && data->colors.g == -1)
		data->colors.g = ft_atoi(&line[*i]);
	else if (check_com_c == 2 && data->colors.b == -1)
		data->colors.b = ft_atoi(&line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	return (0);
}

void	find_color(t_data *data, char *line)
{
	int check_com_c;
	int check_double_c;
	int i;

	check_com_c = 0;
	check_double_c = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]) && line[i] != 'C')
			exit_program_please("Error\nJunk in the sentence\n");
		if (line[i] == 'C')
			check_double_c++;
		if (check_double_c > 1)
			exit_program_please("Error\nDouble C you weirdo\n");
		if (line[i] == ',')
			check_com_c++;
		if (check_com_c > 2)
			exit_program_please("Error\nToo many color codes\n");
		i++;
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			check_color(data, line, &i, check_com_c);
		data->map.color = create_trgb(data->colors.r,
		data->colors.g, data->colors.b);
	}
}

int		check_floor_color(t_data *data, char *line, int *i, int check_com_f)
{
	if (check_com_f == 0 && data->colors.r == -1)
		data->colors.r = ft_atoi(&line[*i]);
	else if (check_com_f == 1 && data->colors.g == -1)
		data->colors.g = ft_atoi(&line[*i]);
	else if (check_com_f == 2 && data->colors.b == -1)
		data->colors.b = ft_atoi(&line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	return (0);
}

void	find_floor_color(t_data *data, char *line)
{
	int check_com_f;
	int check_double_f;
	int i;

	check_com_f = 0;
	check_double_f = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]) && line[i] != 'F')
			exit_program_please("Error\nJunk in the sentence\n");
		if (line[i] == 'F')
			check_double_f++;
		if (check_double_f > 1)
			exit_program_please("Error\nDouble F you weirdo\n");
		if (line[i] == ',')
			check_com_f++;
		if (check_com_f > 2)
			exit_program_please("Error\nToo many color codes\n");
		i++;
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			check_floor_color(data, line, &i, check_com_f);
		data->map.floor_color = create_trgb(data->colors.r,
		data->colors.g, data->colors.b);
	}
}

void	color(t_data *data, char *line)
{
	static int	check_f;

	if (ft_strchr(line, 'F'))
	{
		if (ft_strchr(line, '-'))
			exit_program_please("Error\nColors are minus\n");
		check_f++;
		if (check_f > 1)
			exit_program_please("Error\nDouble line\n");
		find_floor_color(data, line);
		if (data->colors.r < 0 || data->colors.g < 0 || data->colors.b < 0)
			exit_program_please("Error\nColors are minus\n");
		if (data->colors.r > 255 || data->colors.g > 255
		|| data->colors.b > 255)
			exit_program_please("Error\nColors are higher than 255\n");
		if (data->map_start == 1)
			exit_program_please("Error\nF after map!\n");
	}
	check_ceiling_color(data, line);
	data->colors.r = -1;
	data->colors.g = -1;
	data->colors.b = -1;
}
