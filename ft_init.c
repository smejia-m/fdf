/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:47:01 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/11 12:47:03 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**fonction qui initisialise la structure t_parse
*/

t_parse			*ft_parse_ini(void)
{
	t_parse		*params;

	if (!(params = (t_parse *)malloc(sizeof(t_parse))))
		return (NULL);
	params->tab = NULL;
	params->index_y = 0;
	params->index_x = 0;
	params->count_lines = 0;
	params->tmp_len = 0;
	params->len = 0;
	params->ret = 0;
	return (params);
}

/*
** fonction qu'initialise la structure image
*/

t_image			*init_struct_img(t_wparam *wparam, int width, int height)
{
	t_image		*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(wparam->mlx, width, height);
	image->data = (t_pixel *)mlx_get_data_addr(image->img,
	&bits_per_pixel, &size_line, &endian);
	image->htile = 2;
	image->wtile = 4;
	image->width = width;
	image->height = height;
	image->color = 0x0094BF8B;
	return (image);
}
