/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:21 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/15 14:43:50 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	void					*dst;
	const unsigned char		*str;

	i = 0;
	str = s;
	while (n != 0)
	{
		if (str[i] == (unsigned char)c)
		{
			dst = (void *)&str[i];
			return (dst);
		}
		i++;
		n--;
	}
	return (NULL);
}
