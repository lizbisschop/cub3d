/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:25:43 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/19 11:25:44 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	c2;

	i = 0;
	str = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
			return (&str[i]);
		else
			i++;
	}
	return (0);
}
