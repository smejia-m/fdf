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
*/

void	ft_axex(t_param *params, t_image *image)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < params->height)
	{
		while (x < params->width - 1)
		{
			if (params->tab[y][x] != 0)//droites haut et descendantes  x
			{
				trace_dxz(x, y, params->tab, image);
			}
			else if (params->tab[y][x + 1] != 0)// droites montantes x
			{
				trace_dxz(x, y, params->tab, image);
			}
			else // droites bases x
				trace_dx(x, y, image);
			++x;
		}
		x = 0;
		++y;
	}
}

/*
** dessine les axes y
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
			if (params->tab[y][x] != 0)//droites hautes et descendantes y
				trace_dyz(x, y, params->tab, image);
			else if (params->tab[y + 1][x] != 0)//droites momtantes y
				trace_dyz(x, y, params->tab, image);
			else // droites bases y
				trace_dy(x, y, image);
			++y;
		}
		y = 0;
		++x;
	}
}
