/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 13:56:26 by liz           #+#    #+#                 */
/*   Updated: 2020/06/25 16:56:06 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		header(t_data *data, int fd)
{
	char	s[54];
	int		padding;

	padding = 0;
	ft_bzero(s, 54);
	s[0] = 0x42;
	s[1] = 0x4d;
	while ((3 * data->width + padding) % 4 != 0)
		padding++;
	s[2] = 3 * (data->width + padding) * data->height + 54;
	s[10] = 54;
	s[14] = 40;
	ft_memcpy(s + 18, &data->width, 4);
	ft_memcpy(s + 22, &data->height, 4);
	s[26] = 1;
	s[28] = 24;
	write(fd, s, 54);
	return (padding);
}

void	while_loop_bmp(t_data *data, int fd, int len)
{
	int		x;
	char	*string;

	x = 0;
	while (x < data->width)
	{
		string = (data->mlx.addr + (len * data->mlx.line_length
		+ x * (data->mlx.bits_per_pixel / 8)));
		x++;
		write(fd, string, 3);
	}
}

int		create_bmp(t_data *data)
{
	int fd;
	int padding;
	int len;

	fd = open("bitmap.bmp", O_RDWR | O_CREAT, 0666);
	padding = header(data, fd);
	len = data->height - 1;
	while (len >= 0)
	{
		while_loop_bmp(data, fd, len);
		write(fd, "\0\0\0", padding);
		len--;
	}
	close(fd);
	return (0);
}
