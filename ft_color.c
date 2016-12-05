/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:16:50 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/30 11:17:06 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel ft_color(int z)
{
	//t_pixel pixel;

	//pixel = 0xffffff;
	if (z < 0 )
		return (0x008DC1EA);
	else if (z >= 0 && z < 3)
		return (0x0094BF8B);
	else if (z >= 3 && z < 6)
		return (0x00DED6A3);
	else if (z >= 6 && z < 9)
		return (0x00AA8753);
	else if (z >= 9)
		return (0x00FFFFFF);
	return(0x00FFFFFF);
}
/*
#include "fdf.h"
static void ft_color2(t_pixel *p1, double ref)
{
    if (ref < -500)
        p1->col = 255 * (23 * 1);
    else if (ref < -400)
        p1->col = 255 * (23 * 2);
    else if (ref < -300)
        p1->col = 255 * (23 * 3);
    else if (ref < -200)
        p1->col = 255 * (23 * 4);
    else if (ref < -100)
        p1->col = 255 * (23 * 5);
    else if (ref < 0)
        p1->col = 255 * (23 * 6);
    else if (ref < 100)
        p1->col = 255 * (23 * 7);
    else if (ref < 200)
        p1->col = 255 * (23 * 8);
    else if (ref < 300)
        p1->col = 255 * (23 * 9);
    else if (ref < 400)
        p1->col = 255 * (23 * 10);
    else
        p1->col = 255 * (23 * 11);
}
static void ft_color(t_pixel f, t_pixel s, t_pixel *p1)
{
    double  ref;
    if (f.z >= 0 && s.z >= 0)
    {
        if (f.z > s.z)
            ref = f.z;
        else
            ref = s.z;
    }
    else
    {
        if (f.z < s.z)
            ref = f.z;
        else
            ref = s.z;
    }
    ft_color2(p1, ref);
}
static void ft_initpoint(t_mat *tmp, t_pixel *p1, t_pixel *p2, int i)
{
    t_pixel f;
    t_pixel s;
    int     decalx;
    int     decaly;
    decaly = (int)(tmp->size) % 20 * 40;
    decalx = (int)(tmp->size) % 30 * 20;
    f.x = (i) * tmp->unity;
    f.y = -(tmp->y) * tmp->unity;
    f.z = ft_atoi((const char*)(tmp->tab[i])) * tmp->zunity;
    p1->x = (sqrt(2) / 2 * (f.x - f.y) + decalx) + tmp->xmarge;
    p1->y = (-(1 / sqrt(6)) * (f.x + f.y) + decaly - sqrt(2.0 / 3.0) * f.z) + \
    tmp->ymarge;
    p2->x = p1->x;
    p2->y = p1->y;
    if (tmp->next)
    {
        s.x = (i) * tmp->unity;
        s.y = -(tmp->next->y) * tmp->unity;
        s.z = ft_atoi((const char*)(tmp->next->tab[i])) * tmp->zunity;
        p2->x = (sqrt(2) / 2 * (s.x - s.y) + decalx) + tmp->xmarge;
        p2->y = (-(1 / sqrt(6)) * (s.x + s.y) + decaly - sqrt(2.0 / 3.0) \
            * s.z) + tmp->ymarge;
    }
    ft_color(f, s, p1);
}
void        ft_vline(t_env *e, int col)
{
    t_pixel p1;
    t_pixel p2;
    int     i;
    t_mat   *tmp;
    size_t  size;
    size = e->mat->size;
    tmp = e->mat;
    p1.col = col;
    while (tmp->next)
    {
        i = 0;
        while (tmp->tab[i])
        {
            tmp->xmarge = e->mat->xmarge;
            tmp->ymarge = e->mat->ymarge;
            tmp->unity = e->mat->unity;
            tmp->zunity = e->mat->zunity;
            tmp->size = size;
            ft_initpoint(tmp, &p1, &p2, i);
            ft_line(e, p1, p2);
            ++i;
        }
        tmp = tmp->next;
    }
}
*/