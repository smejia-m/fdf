/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 09:56:01 by smejia-m          #+#    #+#             */
/*   Updated: 2016/10/25 09:56:17 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



/*
**fonction qui trace des droites
*/

void traceif(int dx, int dy, int x, int y, t_image *image)
{
  int cumul;
  int i;
  int xinc;
  int yinc;

  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  cumul = dx / 2;
  i = 1;
  while (i <= dx) 
    {
      x += xinc;
      cumul += dy;
      if (cumul >= dx)
      {
        cumul -= dx;
        y += yinc;
      }
      my_pixel_put(image, x, y, image->color);
      i++;
    }
}


void traceelse(int dx, int dy, int x, int y, t_image *image)
{
  int cumul;
  int i;
  int xinc;
  int yinc;


  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  cumul = dy / 2;
  i = 1;
  while (i <= dy)
    {
      y += yinc;
      cumul += dx;
      if (cumul >= dy)
      {
        cumul -= dy;
        x += xinc;
      }
      my_pixel_put(image, x, y, image->color);
      i++;
    }
}
 
void  ft_tracer(int xi, int yi, int xf, int yf, t_image *image) 
{
  int dx;
  int dy;
  int i;
  int xinc;
  int yinc;
  int cumul;
  int x;
  int y;

  x = xi;
  y = yi;
  dx = xf - xi;
  dy = yf - yi;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx);
  dy = abs(dy);
  my_pixel_put(image, x, y, image->color);
  if (dx > dy)
  {
    traceif(dx, dy, x, y, image);
  	/*cumul = dx / 2;
    i = 1;
    while (i <= dx) 
    {
      x += xinc;
      cumul += dy;
      if (cumul >= dx)
      {
        cumul -= dx;
        y += yinc;
      }
     my_pixel_put(image, x, y, image->color);
      i++;
    }*/
  }
  else
  {
    //traceelse(dx, dy, x, y, image);
  	cumul = dy / 2;
  	i = 1;
    while (i <= dy)
    {
      y += yinc;
      cumul += dx;
      if (cumul >= dy)
      {
        cumul -= dy;
        x += xinc;
      }
    //my_pixel_put(image, x, y, image->color);
    i++;
  	}
  }
}
