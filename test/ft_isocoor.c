/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isocoor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:07:34 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/30 10:07:37 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fonction qui transforme les coordonnes en coordonnes isometrique
*/

int		ft_isocoorx(int x, int y, t_image *image)
{
	int ret;

	y = y + (image->rayon * sin(image->alpha));
	x = x + (image->rayon *cos(image->alpha)); 
	ret = (x - y) * image->wtile + image->width / 2;
	return (ret);
}

int		ft_isocoory(int x, int y, t_image *image)
{
	int ret;
	
	y = y + (image->rayon * sin(image->alpha));
	x = x + (image->rayon *cos(image->alpha)); 
	ret = (x + y) * image->htile + image->height / 2;
	return (ret);
}

int		ft_isocoorz(int x, int y, int z, t_image *image)
{
	int	ret;

	y = y + (image->rayon * sin(image->alpha));
	x = x + (image->rayon *cos(image->alpha)); 
	z = z + (image->rayon * sin(image->alpha));
	ret = (x + y - z) * image->htile + image->height / 2;
	return (ret);
}
