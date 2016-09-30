/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:07:23 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/23 09:05:53 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		if (s)
		{
			while (s[i] != 0)
			{
				dst[i] = f(i, s[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
