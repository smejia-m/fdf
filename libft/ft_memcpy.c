/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:42:17 by smejia-m          #+#    #+#             */
/*   Updated: 2016/01/11 10:09:09 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *)src;
	b = (char *)dst;
	while (n != 0)
	{
		b[i] = a[i];
		i++;
		n--;
	}
	return (dst);
}
