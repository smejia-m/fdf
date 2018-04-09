/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:44:55 by smejia-m          #+#    #+#             */
/*   Updated: 2018/04/07 15:45:01 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fonction qui augment la valeur de z
*/

int				aug_z(t_wparam *wparam, int ret)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < wparam->params->height)
	{
		while (x < wparam->params->width)
		{
			if (wparam->params->tab[y][x] == -1)
				wparam->params->tab[y][x] += 2;
			if (wparam->params->tab[y][x] != 0)
				wparam->params->tab[y][x]++;
			x++;
		}
		x = 0;
		y++;
	}
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

/*
** fonction qui baisse la valeur de z
*/

int				min_z(t_wparam *wparam, int ret)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < wparam->params->height)
	{
		while (x < wparam->params->width)
		{
			if (wparam->params->tab[y][x] == 1)
				wparam->params->tab[y][x] -= 2;
			if (wparam->params->tab[y][x] != 0)
				wparam->params->tab[y][x]--;
			x++;
		}
		x = 0;
		y++;
	}
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}
