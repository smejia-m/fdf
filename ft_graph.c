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

/*
** fonction qui transforme les coordonnes en coordonnes isometrique
*/


int ft_isocoorx(int x, int y, t_image *image)
{
  int ret;

  ret = (x - y) * image->wtile + image->width / 3;
  return (ret);
}

int ft_isocoory(int x, int y, t_image *image)
{
  int ret;

  ret = (x + y) * image->htile + image->height / 3;
  return (ret);
}

int ft_isocoorz(int x, int y, int z, t_image *image)
{
  int ret;

  ret = (x + y - z) * image->htile + image->height / 3;
  return (ret);
}

void trace_dx(int x, int y, t_image *image)
{
  int xi;
  int yi;
  int xf;
  int yf;

  xi = ft_isocoorx(x, y, image);
  yi = ft_isocoory(x, y, image);
  xf = ft_isocoorx(x + 1, y, image);
  yf = ft_isocoory(x + 1, y, image);
  image->color = 0x0094BF8B;//
  ft_tracer(xi, yi, xf, yf, image);
}

void trace_dy(int x, int y, t_image *image)
{
  int xi;
  int yi;
  int xf;
  int yf;

  xi = ft_isocoorx(x, y, image);
  yi = ft_isocoory(x, y, image);
  xf = ft_isocoorx(x, y + 1, image);
  yf = ft_isocoory(x, y + 1, image);
  image->color = 0x0094BF8B;//
  ft_tracer(xi, yi, xf, yf, image);
}


void trace_dxz(int x, int y, int **tab, t_image *image)
{
  int xi;
  int yi;
  int xf;
  int yf;

  xi = ft_isocoorx(x, y, image);
  yi = ft_isocoorz(x, y, tab[y][x], image);
  xf = ft_isocoorx(x + 1, y, image);
  yf = ft_isocoorz(x + 1, y, tab[y][x + 1], image);
  image->color = 0x00DED6A3;//
  ft_tracer(xi, yi, xf, yf, image);
}

void trace_dyz(int x, int y, int **tab, t_image *image)
{
  int xi;
  int yi;
  int xf;
  int yf;

  xi = ft_isocoorx(x, y, image);
  yi = ft_isocoorz(x, y, tab[y][x], image);
  xf = ft_isocoorx(x, y + 1, image);
  yf = ft_isocoorz(x, y + 1, tab[y + 1][x], image);
  image->color = 0x00DED6A3;//
  ft_tracer(xi, yi, xf, yf, image);
}

/*
** dessine les axes x
*/

void ft_axex(t_param *params, t_image *image)
{
  int x;
  int y;

  x = 0;
  y = 0;
  while (y < params->height)
  {
    while(x < params->width - 1)
    { 
        if(params->tab[y][x] != 0) //droites haut et descendantes  x
        {
          trace_dxz(x, y, params->tab, image);
        }
        else if(params->tab[y][x + 1] != 0) // droites montantes x
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

void ft_axey(t_param *params, t_image *image)
{
  int x;
  int y;

  x = 0;
  y = 0;
  while(x < params->width)
  {
    while (y < params->height - 1) 
    { 
      if(params->tab[y][x] != 0) //droites hautes et descendantes y
        trace_dyz(x, y, params->tab, image);
      else if(params->tab[y + 1][x] != 0) //droites momtantes y 
        trace_dyz(x, y, params->tab, image);
      else // droites bases y
        trace_dy(x, y, image);
      ++y;
    }
    y = 0;
    ++x;
  } 
}