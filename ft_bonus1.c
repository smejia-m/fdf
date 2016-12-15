/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:22:18 by smejia-m          #+#    #+#             */
/*   Updated: 2016/12/06 15:22:19 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fonction qui zoom en avant
*/

int				more_zoom(t_wparam *wparam, int ret)
{
	wparam->image->wtile = wparam->image->wtile + 2;
	++wparam->image->htile;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

/*
** fonction qui zoom en arriere
*/

int				less_zoom(t_wparam *wparam, int ret)
{
	ret = mlx_clear_window(wparam->mlx, wparam->win);
	wparam->image->wtile = wparam->image->wtile - 2;
	--wparam->image->htile;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

/*
** fonction qui ferme la fenetre en appuyant sur la croix rouge avec la souris
*/

int				close_cross(int n)
{
	exit(n);
	return (n);
}

/*
**fonction qui dessine un pixel lorsque on clique sur la souris
*/

int				my_mouse_func(int mousecode, int x, int y, t_wparam *param)
{
	mlx_pixel_put(param->mlx, param->win, x, y, 0xFFFFFF);
	ft_putnbr(mousecode);
	return (0);
}

/*
** fonction qui augment la valeur de z
*/

int				aug_z(t_wparam *wparam, int ret)
{
	int x;
	int y;

	ret = mlx_clear_window(wparam->mlx, wparam->win);
	x = wparam->params->width;
	y = wparam->params->height;
	while(y < wparam->params->height)
	{
		while (x < wparam->params->width)
		{
			if(wparam->params->tab[y][x] != 0)
				wparam->params->tab[y][x]++;
			x++;
		}
		y++;
	}
	return (ret);
}
