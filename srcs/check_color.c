/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 16:21:30 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/29 17:10:28 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_ceiling_color(t_data *data, char *line)
{
	static int check_c;

	if (ft_strchr(line, 'C'))
	{
		if (ft_strchr(line, '-'))
			exit_program_please("Error\nColors are minus\n");
		check_c++;
		if (check_c > 1)
			exit_program_please("Error\nDouble line\n");
		find_color(data, line);
		if (data->colors.r < 0 || data->colors.g < 0 || data->colors.b < 0)
			exit_program_please("Error\nColors are minus\n");
		if (data->colors.r > 255 || data->colors.g > 255
		|| data->colors.b > 255)
			exit_program_please("Error\nColors are higher than 255\n");
		if (data->map_start == 1)
			exit_program_please("Error\nC after map!\n");
	}
}
