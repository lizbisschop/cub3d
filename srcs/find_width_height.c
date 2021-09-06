/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_width_height.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 13:22:52 by liz           #+#    #+#                 */
/*   Updated: 2020/07/03 11:08:54 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_width_height_2(t_data *data, char *line)
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
	if ((data->height > 1400 && data->save != 1)
	|| (data->width > 2560 && data->save != 1))
		mlx_get_screen_size(data->mlx.mlx, &data->width, &data->height);
	if (data->height <= 0 || data->width <= 0 ||
	data->height > 16348 || data->width > 16348)
		exit_program_please("Error\nThere is an error in the window\n");
	if (data->map_start == 1)
		exit_program_please("Error\nR after map!\n");
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
				exit_program_please("Error\nWrong map input\n");
			i++;
		}
		if (ft_isalpha(line[i]) && line[i] != 'R')
			exit_program_please("Error\nWrong map input\n");
		i++;
	}
	find_width_height_2(data, line);
	return (0);
}
