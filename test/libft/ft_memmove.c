/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:56:58 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/18 09:13:27 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*temp_src;
	char			*temp_dst;

	temp_dst = dst;
	temp_src = src;
	if (dst <= src)
	{
		return (ft_memcpy(dst, src, len));
	}
	temp_dst = temp_dst + len;
	temp_src = temp_src + len;
	while (len--)
		*--temp_dst = *--temp_src;
	return (dst);
}
