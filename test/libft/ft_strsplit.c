/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:00:33 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/16 08:48:59 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static	int		count(char const *s, char c)
{
	size_t		i;
	int			len;

	i = 1;
	len = 0;
	while (s[i] != '\0')
	{
		if ((s[i - 1] != c && s[i] == c) || (i == 0 && s[i] != c)
			|| (i == ft_strlen(s) - 1 && s[i] != c))
			len++;
		i++;
	}
	return (len);
}

static	void	ft_cp(const char *s, char c, char **dst)
{
	int			debut;
	int			fin;
	int			i;
	int			j;

	i = 0;
	j = 0;
	debut = 0;
	fin = 0;
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		debut = i;
		while (s[i] && s[i] != c)
			i++;
		fin = i;
		if (fin != debut)
		{
			dst[j] = ft_strsub(s, (unsigned int)debut, fin - debut);
			j++;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		**dst;

	len = 0;
	if (!s)
		return (NULL);
	len = count(s, c);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	if (ft_strequ(s, ""))
		dst[0] = NULL;
	else
		ft_cp(s, c, dst);
	return (dst);
}
