/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:13:35 by liz           #+#    #+#                 */
/*   Updated: 2020/07/03 11:13:17 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != '\0' || str2[i] != 0)
		return (0);
	return (1);
}

void	get_address_tex(t_data *data)
{
	int i;

	i = 0;
	while (i < 7)
	{
		data->textures[i].texture_adrr =
		(int *)mlx_get_data_addr(data->textures[i].tex,
		&data->textures[i].bits_per_pixel, &data->textures[i].line_length,
		&data->textures[i].endian);
		i++;
	}
}

int		close_screen(void)
{
	exit_program_please("Window has been closed, Goodbye!!\n");
	return (0);
}

void	if_statements_main(t_data *data, char **argv)
{
	if (argv[2] == NULL)
		loop(data);
	if (ft_strcmp(argv[2], "--save"))
	{
		raycasting(data);
		create_bmp(data);
		exit(0);
	}
	if (!ft_strcmp(argv[2], "--save"))
		exit_program_please("Error\nThe second arguments should be --save\n");
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		exit_program_please("Error\nMap file does not excist!!\n");
	if (argc >= 4)
		exit_program_please("Error\nToo many arguments\n");
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		exit_program_please("Error\nMap file does not excist!!\n");
	set_all_to_zero(&data);
	if (argv[2] != NULL && ft_strcmp(argv[2], "--save"))
		data.save = 1;
	get_all_data(&data, argv);
	if (data.map.map == NULL)
		exit_program_please("Error\nMap does not excist!!\n");
	get_address_tex(&data);
	raycasting(&data);
	if_statements_main(&data, argv);
	return (0);
}
