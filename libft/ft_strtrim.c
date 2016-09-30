/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:58:34 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/09 17:13:08 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		fin;
	size_t		len;
	char		*dst;

	i = 0;
	fin = 0;
	dst = NULL;
	if (s != NULL)
	{
		len = ft_strlen(s);
		fin = len;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			++i;
		while (s[fin - 1] == ' ' || s[fin - 1] == '\n' || s[fin - 1] == '\t')
			--fin;
		if (fin < i)
			fin = i;
		len = fin - i;
		dst = ft_strsub(s, i, len);
	}
	return (dst);
}
