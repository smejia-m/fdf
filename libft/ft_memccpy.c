/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:01:05 by smejia-m          #+#    #+#             */
/*   Updated: 2016/01/11 10:02:19 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		j;
	const unsigned char	*a;
	unsigned char		*b;

	i = 0;
	a = src;
	b = dst;
	j = (unsigned char)c;
	while (i < n)
	{
		b[i] = a[i];
		if (b[i] == j)
		{
			b = &b[++i];
			return (b);
		}
		i++;
	}
	return (NULL);
}
