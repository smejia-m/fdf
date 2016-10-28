/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:48:25 by smejia-m          #+#    #+#             */
/*   Updated: 2016/10/28 15:48:29 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void trace_dx(int x, int y, t_image *image)
{
  int xi;
  int yi;
  int xf;
  int yf;

  xi = 0;
  yi = 0;
  xf = 0;
  yf = 0;
  xi = (x - y) * image->wtile + image->width / 2;
  yi = (x + y)  * image->htile + image->height / 2;
  xf = (x + 1 - y) * image->wtile + image->width / 2;
  yf = (x + 1 + y) * image->htile + image->height / 2;
  image->color = 0x0094BF8B;//
  ft_tracer(xi, yi, xf, yf, image);
}

/*
** dessine les axes x
*/

void ft_axex(t_param *params, t_image *image)
{
  int x;
  int y;
  int xi;
  int yi;
  int xf;
  int yf;

  x = 0;
  y = 0;
  xi = 0;
  yi = 0;
  xf = 0;
  yf = 0;
  while (y < params->height)
  {
    while(x < params->width - 1)
    { 
        if(params->tab[y][x] != 0) //droites haut et descendantes  x
        {
          xi = (x - y) * image->wtile + image->width / 2;
          yi = ((x + y) - params->tab[y][x]) * image->htile + image->height / 2;
          xf = (x + 1 - y) * image->wtile + image->width / 2;
          yf = ((x + 1 + y) - params->tab[y][x + 1]) * image->htile + image->height / 2;
          image->color = 0x00DED6A3;//
          ft_tracer(xi, yi, xf, yf, image);
        }
        else if(params->tab[y][x + 1] != 0) // droites montantes x
        {
          xi = (x - y) * image->wtile + image->width / 2;
          yi = ((x + y) - params->tab[y][x]) * image->htile + image->height / 2;
          xf = (x + 1 - y) * image->wtile + image->width / 2;
          yf = ((x + 1 + y) - params->tab[y][x + 1]) * image->htile + image->height / 2;
          image->color = 0x00DED6A3;//
          ft_tracer(xi, yi, xf, yf, image);
        }
        else // droites bases x
          trace_dx(x, y, image);
        ++x;
    }
    x = 0;
    ++y;
  } 
}

void ft_axey(t_param *params, t_image *image)
{
  int x;
  int y;
  int xi;
  int yi;
  int xf;
  int yf;

  x = 0;
  y = 0;
  xi = 0;
  yi = 0;
  xf = 0;
  yf = 0;
  while(x < params->width)
  {
    while (y < params->height - 1) 
    { 
      if(params->tab[y][x] != 0) //droites hautes et descendantes y
      {
        xi = (x - y) * image->wtile + image->width / 2;
        yi = ((x + y) - params->tab[y][x]) * image->htile + image->height / 2;
        xf = (x - (y + 1)) * image->wtile + image->width / 2;
        yf = ((x + (y + 1)) - params->tab[y + 1][x]) * image->htile + image->height / 2;
        image->color = 0x00DED6A3;
        ft_tracer(xi, yi, xf, yf, image);
      }
      else if(params->tab[y + 1][x] != 0) //droites momtantes y 
      {
        xi = (x - y) * image->wtile + image->width / 2;
        yi = ((x + y) - params->tab[y][x]) * image->htile + image->height / 2;
        xf = (x - (y + 1)) * image->wtile + image->width / 2;
        yf = ((x + (y + 1)) - params->tab[y + 1][x]) * image->htile + image->height / 2;
        image->color = 0x00DED6A3;
        ft_tracer(xi, yi, xf, yf, image);
      }
      else // droites bases y
      {
        xi = (x - y) * image->wtile + image->width / 2;
        yi = (x + y)  * image->htile + image->height / 2;
        xf = (x - (y + 1)) * image->wtile + image->width / 2;
        yf = (x + (y + 1)) * image->htile + image->height / 2;
        image->color = 0x0094BF8B;
        ft_tracer(xi, yi, xf, yf, image);
      }
      ++y;
    }
    y = 0;
    ++x;
  } 
}