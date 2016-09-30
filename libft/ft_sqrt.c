/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:05:25 by smejia-m          #+#    #+#             */
/*   Updated: 2016/08/08 14:16:25 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	result;

	result = 1;
	while (result < nb)
	{
		if (result * result >= nb)
			return (result);
		++result;
	}
	return (1);
}
