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

	ret = (x - y) * image->wtile + image->width / 3;
	return (ret);
}

int		ft_isocoory(int x, int y, t_image *image)
{
	int ret;

	ret = (x + y) * image->htile + image->height / 3;
	return (ret);
}

int		ft_isocoorz(int x, int y, int z, t_image *image)
{
	int	ret;

	ret = (x + y - z) * image->htile + image->height / 3;
	return (ret);
}
