/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:24:28 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/09 17:29:06 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;

	dst = NULL;
	if (s1 && s2)
	{
		dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (dst)
		{
			dst = ft_strcat(dst, s1);
			dst = ft_strcat(dst, s2);
			return (dst);
		}
	}
	return (dst);
}
