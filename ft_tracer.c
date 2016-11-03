/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 09:56:01 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/01 13:39:28 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**fonction qui trace des droites
*/

void		traceif(t_trace trace, t_image *image)
{
	int		i;
	int		cumul;

	cumul = trace.dx / 2;
	i = 1;
	while (i <= trace.dx)
	{
		trace.x += trace.xinc;
		cumul += trace.dy;
		if (cumul >= trace.dx)
		{
			cumul -= trace.dx;
			trace.y += trace.yinc;
		}
		my_pixel_put(image, trace.x, trace.y, image->color);
		i++;
	}
}

void		traceelse(t_trace trace, t_image *image)
{
	int		cumul;
	int		i;

	cumul = trace.dy / 2;
	i = 1;
	while (i <= trace.dy)
	{
		trace.y += trace.yinc;
		cumul += trace.dx;
		if (cumul >= trace.dy)
		{
			cumul -= trace.dy;
			trace.x += trace.xinc;
		}
		my_pixel_put(image, trace.x, trace.y, image->color);
		i++;
	}
}

void		ft_tracer(int xi, int yi, int xf, int yf, t_image *image)
{
	t_trace	trace;

	trace.x = xi;
	trace.y = yi;
	trace.dx = xf - xi;
	trace.dy = yf - yi;
	trace.xinc = (trace.dx > 0) ? 1 : -1;
	trace.yinc = (trace.dy > 0) ? 1 : -1;
	trace.dx = abs(trace.dx);
	trace.dy = abs(trace.dy);
	my_pixel_put(image, trace.x, trace.y, image->color);
	if (trace.dx > trace.dy)
		traceif(trace, image);
	else
		traceelse(trace, image);
}
