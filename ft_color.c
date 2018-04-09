/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:16:50 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/30 11:17:06 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	ft_color_plus(int z)
{
	if (z >= 0 && z < 1)
		return (0x00ACD0A5);
	else if (z >= 1 && z < 2)
		return (0x00A8C68F);
	else if (z >= 2 && z < 3)
		return (0x00D1D7AB);
	else if (z >= 3 && z < 4)
		return (0x00EFEBC0);
	else if (z >= 4 && z < 5)
		return (0x00D3CA9D);
	else if (z >= 5 && z < 7)
		return (0x00CAB982);
	else if (z >= 7 && z < 8)
		return (0x00B9985A);
	else if (z >= 8 && z < 10)
		return (0x00BAAE9A);
	else if (z >= 10)
		return (0x00FFFFFF);
	return (0x00ACD0A5);
}

static t_pixel	ft_color_moins(int z)
{
	if (z < -10)
		return (0x008DC1EA);
	else if (z >= -10 && z < -6)
		return (0x0071ABD8);
	else if (z >= -6 && z < -2)
		return (0x0096C9F0);
	else if (z >= -2 && z < 0)
		return (0x00B9E3FF);
	return (0x000978AB);
}

t_pixel			ft_color(int z)
{
	t_pixel	pixel;

	pixel = 0x00FFFFFF;
	if (z >= 0)
	{
		pixel = ft_color_plus(z);
	}
	if (z < 0)
	{
		pixel = ft_color_moins(z);
	}
	return (pixel);
}
