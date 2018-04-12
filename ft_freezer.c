/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freezer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:23:57 by smejia-m          #+#    #+#             */
/*   Updated: 2018/04/08 17:24:01 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** del et free un tableau d'ints
*/


void freetabint(int **tab, int x)
{
    int i;
    
    i = 0;
    while (i < x)
    {
        ft_putstr("S\n");
        free(tab[i]);
        i++;
    }
    ft_putstr("wrong-wronf\n");
    free(tab);
}

