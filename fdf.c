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
** fonction qui zoom en avant
*/

int				more_zoom(t_wparam *wparam, int ret)
{
	wparam->image->wtile = wparam->image->wtile + 2;
	++wparam->image->htile;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

/*
** fonction qui zoom en arriere
*/

int				less_zoom(t_wparam *wparam, int ret)
{
	ret = mlx_clear_window(wparam->mlx, wparam->win);
	wparam->image->wtile = wparam->image->wtile - 2;
	--wparam->image->htile;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

/*
** fonctions de deplacement cardinal
*/

int				go_right(t_wparam *wparam, int ret)
{
	wparam->image->x -= 10;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

int				go_left(t_wparam *wparam, int ret)
{
	wparam->image->x += 10;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

int				go_up(t_wparam *wparam, int ret)
{
	wparam->image->y -= 10;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
}

int				go_down(t_wparam *wparam, int ret)
{
	wparam->image->y += 10;
	ret = ft_draw_img(wparam, wparam->params, wparam->image);
	return (ret);
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
	if (keycode == 14 && wparam->image->wtile < 50)
		ret = more_zoom(wparam, ret);
	if (keycode == 12 && wparam->image->wtile > 0)
		ret = less_zoom(wparam, ret);
	if (keycode == 2)
		ret = go_right(wparam, ret);
	if (keycode == 0)
		ret = go_left(wparam, ret);
	if (keycode == 13)
		ret = go_up(wparam, ret);
	if (keycode == 1)
		ret = go_down(wparam, ret);
	if (keycode == 53)
		exit(0);
	return (ret);
}

/*
** fonction qui dessine un pixel sur l'image memoire
*/

void			my_pixel_put(t_image *image, int x, int y, t_pixel pixel)
{
	unsigned int i;
	unsigned int len;//

	len = 0;//
	if (x >= image->width || y >= image->height)
		return ;
	i = ((y * image->width) + x);
	len = ft_strlen(image->data);//
	if (len < i)//
		return;//
	image->data[i] = pixel;
		return ;
}

/*
**fonction qui dessine un pixel lorsque on clique sur la souris
*/

int				my_mouse_func(int mousecode, int x, int y, t_wparam *param)
{
	mlx_pixel_put(param->mlx, param->win, x, y, 0xFFFFFF);
	ft_putnbr(mousecode);
	return (0);
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
	image->x = 0;
	image->y = 0;
	image->color = 0x0094BF8B;
	return (image);
}

/*
** fonction qui cree une image en memoire
*/

int				ft_draw_img(t_wparam *wparam, t_param *params, t_image *image)
{
	ft_axex(params, image);
	ft_axey(params, image);
	mlx_put_image_to_window(wparam->mlx,
		wparam->win, image->img, image->x, image->y);
	return (0);
}

/*
** fonction qui ferme la fenetre en appuyant sur la croix rouge avec la souris
*/

int				close_cross(int n)
{
	exit(n);
	return (n);
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
