/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:11:34 by smejia-m          #+#    #+#             */
/*   Updated: 2018/04/09 14:13:28 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	len1 = 0;
	len2 = 0;
	dest = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		dest = ft_memalloc(len1 + len2 + 1);
		if (dest)
		{
			dest = ft_strcat(dest, s1);
			dest = ft_strcat(dest, s2);
			free(s1);
			ft_strclr(s2);
			return (dest);
		}
	}
	free(&dest);
	return (NULL);
}
