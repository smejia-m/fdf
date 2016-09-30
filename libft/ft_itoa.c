/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:25:55 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/09 17:32:26 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static	int	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		return (str);
	}
	len = ft_intlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	len = len - 1;
	if (n > 0)
		n = -n;
	if (n < 0)
		str[0] = '-';
	while (n < 0)
	{
		str[len] = -(n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
