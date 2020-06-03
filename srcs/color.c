/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: liz <liz@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 10:34:28 by liz           #+#    #+#                 */
/*   Updated: 2020/06/02 10:35:23 by liz           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				create_trgb(int r, int g, int b)
{
	return (b << 24 | g << 16 | r << 8);
}

unsigned int	add_shade(double distance, unsigned int color)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int t;

	t = color & 0xFF000000;
	r = color & 0xFF0000;
	g = color & 0xFF00;
	b = color & 0xFF;
	r = (r >> 16) * (1 - distance);
	g = (g >> 8) * (1 - distance);
	b = b * (1 - distance);
	r = r << 16;
	g = g << 8;
	return (t | r | g | b);
}
