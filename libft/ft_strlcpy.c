/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:27:30 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/19 11:27:32 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*destination;
	char	*source;

	i = 0;
	j = 0;
	if (!dst && !src)
		return (0);
	destination = (char*)dst;
	source = (char*)src;
	while (source[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while (source[j] != '\0' && j + 1 < dstsize)
	{
		destination[j] = source[j];
		j++;
	}
	destination[j] = '\0';
	return (i);
}
