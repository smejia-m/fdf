/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:52:43 by smejia-m          #+#    #+#             */
/*   Updated: 2016/09/27 11:09:26 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			clear_map(t_wparam *wparam)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < wparam->image->height)
	{
		while (x < wparam->image->width)
		{
			my_pixel_put(wparam->image, x, y, 0x0);
			++x;
		}
		x = 0;
		++y;
	}
}

/*
**fonction qui dessine un carre en appuyant sur une touche du clavier
*/

int				my_key_func(int keycode, t_wparam *wparam)
{
	int			ret;

	ret = 0;
	ret = mlx_clear_window(wparam->mlx, wparam->win);
	clear_map(wparam);
	if (keycode == 14 && wparam->image->wtile < wparam->win_width)
		ret = more_zoom(wparam, ret);
	if (keycode == 12 && wparam->image->wtile > 0)
		ret = less_zoom(wparam, ret);
	if (keycode == 53)
		exit(0);
	if (keycode == 3)
		ret = aug_z(wparam, ret);
	return (ret);
}

/*
** fonction qui dessine un pixel sur l'image memoire
*/

void			my_pixel_put(t_image *image, int x, int y, t_pixel pixel)
{
	unsigned int i;

	if (x >= image->width || y >= image->height)
		return ;
	i = ((y * image->width) + x);
	image->data[i] = pixel;
	return ;
}

/*
** fonction qui cree une image en memoire
*/

int				ft_draw_img(t_wparam *wparam, t_param *params, t_image *image)
{
	ft_axex(params, image);
	ft_axey(params, image);
	mlx_put_image_to_window(wparam->mlx,
		wparam->win, image->img, 0, 0);
	return (0);
}

/*
**fonction principal qui construit le graphique
*/

int				ft_prin_struct(t_param *params, char *win_name)
{
	t_wparam	*wparam;
	t_image		*image;
	int			ret;

	ret = 0;
	if (!(wparam = (t_wparam *)malloc(sizeof(t_wparam))))
		return (-1);
	wparam->mlx = mlx_init();
	wparam->win_width = 1600;
	wparam->win_height = 1200;
	wparam->win =
	mlx_new_window(wparam->mlx,
	wparam->win_width, wparam->win_height, win_name);
	wparam->image = NULL;
	wparam->params = params;
	if (!(image = init_struct_img(wparam, 1600, 1200)))
		return (-1);
	ret = ft_draw_img(wparam, params, image);
	wparam->image = image;
	mlx_key_hook(wparam->win, my_key_func, (t_param *)wparam);
	mlx_hook(wparam->win, 17, (1L << 17), close_cross, 0);
	mlx_mouse_hook(wparam->win, my_mouse_func, (t_param *)wparam);
	mlx_loop(wparam->mlx);
	return (ret);
}
