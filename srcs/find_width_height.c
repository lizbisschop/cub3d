/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_width_height.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 13:22:52 by liz           #+#    #+#                 */
/*   Updated: 2020/06/03 13:28:24 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		find_width_height_2(t_data *data, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ' || line[i] == 'R')
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

int		find_width_height(t_data *data, char *line)
{
	int			i;
	static int	check_r;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == 'R')
		{
			if (line[i] == 'R')
				check_r++;
			if (check_r > 1)
				exit_program_please(data, "Wrong map input\n");
			i++;
		}
		if (ft_isalpha(line[i]) && line[i] != 'R')
			exit_program_please(data, "Wrong map input\n");
		i++;
	}
	find_width_height_2(data, line);
}
