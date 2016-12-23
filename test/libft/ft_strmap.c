/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:55:01 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/23 09:04:42 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (s)
	{
		dst = (char *)malloc((sizeof(*dst)) * (ft_strlen(s) + 1));
		if (dst == NULL)
			return (NULL);
		if (s && f != NULL)
		{
			while (s[i] != 0)
			{
				dst[i] = f(s[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
