/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:01:54 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/30 10:01:58 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_dx(int x, int y, t_image *image)
{
	int	xi;
	int yi;
	int xf;
	int yf;

	xi = ft_isocoorx(x, y, image);
	yi = ft_isocoory(x, y, image);
	xf = ft_isocoorx(x + 1, y, image);
	yf = ft_isocoory(x + 1, y, image);
	image->color = ft_color(0);
	ft_tracer(xi, yi, xf, yf, image);
}

void	trace_dy(int x, int y, t_image *image)
{
	int xi;
	int yi;
	int xf;
	int yf;

	xi = ft_isocoorx(x, y, image);
	yi = ft_isocoory(x, y, image);
	xf = ft_isocoorx(x, y + 1, image);
	yf = ft_isocoory(x, y + 1, image);
	image->color = ft_color(0);
	ft_tracer(xi, yi, xf, yf, image);
}

void	trace_dxz(int x, int y, int **tab, t_image *image)
{
	int xi;
	int yi;
	int xf;
	int yf;

	xi = ft_isocoorx(x, y, image);
	yi = ft_isocoorz(x, y, tab[y][x], image);
	xf = ft_isocoorx(x + 1, y, image);
	yf = ft_isocoorz(x + 1, y, tab[y][x + 1], image);
	if (tab[y][x] > tab[y][x + 1])
		image->color = ft_color(tab[y][x]);
	else
		image->color = ft_color(tab[y][x + 1]);
	ft_tracer(xi, yi, xf, yf, image);
}

void	trace_dyz(int x, int y, int **tab, t_image *image)
{
	int xi;
	int yi;
	int xf;
	int yf;

	xi = ft_isocoorx(x, y, image);
	yi = ft_isocoorz(x, y, tab[y][x], image);
	xf = ft_isocoorx(x, y + 1, image);
	yf = ft_isocoorz(x, y + 1, tab[y + 1][x], image);
	if (tab[y][x] > tab[y + 1][x])
		image->color = ft_color(tab[y][x]);
	else
		image->color = ft_color(tab[y + 1][x]);
	ft_tracer(xi, yi, xf, yf, image);
}
