/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:09:06 by smejia-m          #+#    #+#             */
/*   Updated: 2016/01/11 10:16:09 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	i;
	size_t	j;

	l = 0;
	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (j >= size || !size || !dst || !src)
		return (i + size);
	while (src[l] != 0 && (j + l) < size - 1)
	{
		dst[j + l] = src[l];
		l++;
	}
	dst[j + l] = '\0';
	return (i + j);
}
