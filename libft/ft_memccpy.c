/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:25:37 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/19 11:25:38 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;
	unsigned char	cha;

	i = 0;
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	cha = (unsigned char)c;
	if (dst == '\0' && src == '\0')
		return (0);
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == cha)
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (0);
}
