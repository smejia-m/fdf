/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 09:18:50 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/23 09:29:59 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		n;
	char	temp;

	i = 0;
	n = ft_strlen(str);
	n--;
	while (i < n)
	{
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		n--;
		i++;
	}
	return (str);
}
