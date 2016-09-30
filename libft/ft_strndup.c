/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:45:23 by smejia-m          #+#    #+#             */
/*   Updated: 2016/09/05 16:45:30 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (n > i)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
