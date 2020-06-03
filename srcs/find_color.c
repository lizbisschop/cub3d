/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_color.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 14:19:04 by liz           #+#    #+#                 */
/*   Updated: 2020/06/03 11:17:46 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_color(t_data *data, char *line, int *i, int check_com_c)
{
	if (check_com_c == 0)
		data->color.r = ft_atoi(&line[*i]);
	else if (check_com_c == 1)
		data->color.g = ft_atoi(&line[*i]);
	else if (check_com_c == 2)
		data->color.b = ft_atoi(&line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
}

int		find_color(t_data *data, char *line)
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
			exit_program_please(data, "junk in the sentence\n");
		if (line[i] == 'C')
			check_double_c++;
		if (check_double_c > 1)
			exit_program_please(data, "Double C you weirdo\n");
		if (line[i] == ',')
			check_com_c++;
		if (check_com_c > 2)
			exit_program_please(data, "to many color codes\n");
		i++;
		if (line[i] >= '0' && line[i] <= '9')
			check_color(data, line, &i, check_com_c);
		data->map.color = create_trgb(data->color.r,
		data->color.g, data->color.b);
	}
}

int		check_floor_color(t_data *data, char *line, int *i, int check_com_f)
{
	if (check_com_f == 0)
		data->color.r = ft_atoi(&line[*i]);
	else if (check_com_f == 1)
		data->color.g = ft_atoi(&line[*i]);
	else if (check_com_f == 2)
		data->color.b = ft_atoi(&line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
}

int		find_floor_color(t_data *data, char *line)
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
			exit_program_please(data, "junk in the sentence\n");
		if (line[i] == 'F')
			check_double_f++;
		if (check_double_f > 1)
			exit_program_please(data, "Double F you weirdo\n");
		if (line[i] == ',')
			check_com_f++;
		if (check_com_f > 2)
			exit_program_please(data, "to many color codes\n");
		i++;
		if (line[i] >= '0' && line[i] <= '9')
			check_floor_color(data, line, &i, check_com_f);
	}
	data->map.floor_color = create_trgb(data->color.r,
	data->color.g, data->color.b);
}

int		color(t_data *data, char *line)
{
	int			i;
	static int	check_f;
	static int	check_c;

	if (ft_strchr(line, 'F'))
	{
		check_f++;
		if (check_f > 1)
			exit_program_please(data, "Double line\n");
		find_floor_color(data, line);
	}
	else if (ft_strchr(line, 'C'))
	{
		check_c++;
		if (check_c > 1)
			exit_program_please(data, "Double line\n");
		find_color(data, line);
	}
}
