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
	wparam->image->htile = wparam->image->htile + 1;
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
