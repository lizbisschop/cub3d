/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:22:11 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/19 11:22:14 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = malloc(sizeof(char) * (count * size));
	if (result == 0)
		return (0);
	while (i < (count * size))
	{
		result[i] = 0;
		i++;
	}
	return ((void*)result);
}
