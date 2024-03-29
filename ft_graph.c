/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:48:25 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/22 14:51:10 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** dessine les axes x
** if droites haut et descendantes  x
** else droites bases x
*/

void	ft_axex(t_param *params, t_image *image)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_putstr("ft_axex 1\n");//
	while (y < params->height)
	{
		ft_putstr("ft_axex 2\n");//
		while (x < params->width - 1)
		{
			ft_putstr("ft_axex 3\n");//
			if ((params->tab[y][x] != 0) || (params->tab[y][x + 1] != 0))
				trace_dxz(x, y, params->tab, image);
			else
				trace_dx(x, y, image);
			++x;
		}
		x = 0;
		++y;
	}
}

/*
** dessine les axes y
** if droites hautes, descendantes y et droites momtantes y
** else droites bases x
*/

void	ft_axey(t_param *params, t_image *image)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < params->width)
	{
		while (y < params->height - 1)
		{
			if ((params->tab[y][x] != 0) || (params->tab[y + 1][x] != 0))
				trace_dyz(x, y, params->tab, image);
			else
				trace_dy(x, y, image);
			++y;
		}
		y = 0;
		++x;
	}
}
