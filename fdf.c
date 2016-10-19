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
#include <math.h>

/*
**fonction qui dessine un carre en appuyant sur une touche du clavier
*/

int my_key_func(int keycode, t_wparam *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("key event %d\n", keycode); //
	while (x < 300)
	{
		while (y < 300)
		{
			mlx_pixel_put(param->mlx, param->win, x , y, 0xFF00FF);
			++y;
		}
		y = 0;
		++x;
	}
	return (0);
}

/*
** fonction qui dessine un pixel sur l'image memoire
*/

void my_pixel_put(t_image *image, int x, int y, t_pixel pixel)
{
	unsigned int i;
	unsigned int imax; //test pour mars

	//printf("image->width: %d, image->height :%d\n ", image->width, image->height);//
	i = ((y * image->width) + x);
	imax = (image->height * image->width);//test mars
	//printf(" i : %d\n", i);//
	//printf("x: %d y : %d\n",x ,y);//
	if(i < imax) // test mars
		image->data[i] = pixel; 
}

/*
**fonction qui dessine un pixel lorsque on clique sur la souris
*/


int my_mouse_func(int mousecode,int x, int y, t_wparam *param)
{
	printf("mouse event %d\n", mousecode);
	printf("coor x %d\n", x);
	printf("coor y %d\n", y);
		mlx_pixel_put(param->mlx, param->win, x, y, 0xFFFFFF);
	return (0);
}

/*
** fonction qu'initialise la structure image 
*/

t_image *init_struct_img(t_wparam *wparam, int width, int height)
{
	t_image *image;
	int bits_per_pixel;
	int size_line;
	int endian;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(wparam->mlx, width, height);
	image->data = (t_pixel *)mlx_get_data_addr(image->img, &bits_per_pixel, &size_line, &endian);
	image->height = height;
	image->width = width;
	image->htile = 1;
	image->wtile = 2;
	//printf("bits_per_pixel : %d, size_line : %d\n", bits_per_pixel, size_line);//
	/*if (bits_per_pixel != 32 || size_line != width * 4)
	{
		return (NULL);
	}*/
	return (image);
}

/*
**fonction qui trace des droites
*/
/*
void ft_tracer(t_point *pointi, t_point *pointf, t_image *image)
{
	int dx;
	int dy;
	int x;
	int y;
	int index;

	dx = pointf->x - pointi->x;
	dy = pointf->y - pointi->x;
	x = pointi->x;
	y = pointf->y;
	my_pixel_put(image, (x - y) * 20 * image->width / 2 , (x + y) * 10 + image->height / 2 , 0x00FFFFFF);
	index = dx / 2;
	if(pointf->x > pointi->x && pointf->y >= pointi->y && (pointf->x - pointi->x) > (pointf->y - pointi->y))
	{
		while (x < pointf->x)
		{
			ft_putchar('q');//
			index = index + dy;
			if( index >= dx)
			{
				index = index - dx;
				y = y + 1;
			}
			my_pixel_put(image, (x - y) * 20 * image->width / 2 , (x + y) * 10 + image->height / 2 , 0x00FFFFFF);
			++x;
		}
	}
}
*/

/*
**transforme les coordonnes en iso
*/

/*t_point *ft_cooriso(t_point *point, t_image *image);
{
 int x;
 int y;
 int z;

x = (point->x - point->y * 



}
*/

/*
** cherche la hauteur et la largeur de l'image

t_param
*/







/*
**fonction principal qui construit le graph
*/


int ft_graph(t_param *params, char *win_name)
{
	t_wparam *wparam;
	t_image *image;
	int x;
	int y;

	x = 0;
	y = 0;
	wparam = (t_wparam *)malloc(sizeof (t_wparam));
	ft_putchar('a');//
	wparam->mlx = mlx_init();
	ft_putchar('b');//
	wparam->win = mlx_new_window(wparam->mlx, 800, 600, win_name);
	ft_putchar('c');//
	if(!(image = init_struct_img(wparam, 800,600)))
		return (-1);
	ft_putchar('d');//
	ft_putstr("height : ");//
	ft_putnbr(params->height);//
	ft_putstr(" width : ");//
	ft_putnbr(params->height);//
	ft_putchar('\n');//
	while (y < params->height)
	{
		ft_putchar('e');//
		while(x < params->width)
		{	
			ft_putchar('f');//
			my_pixel_put(image, (x - y) * image->wtile + image->width / 2, (x + y) * image->htile + image->height / 2, 0x00FF0000);
			if(params->tab[y][x] != 0)
			{
				ft_putchar('g');//
				my_pixel_put(image, (x - y) * image->wtile + image->width / 2, ((x + y) - params->tab[y][x]) * image->htile + image->height / 2, 0x00FFFFFF);
			}
			++x;
		}
		x = 0;
		++y;
	}
	mlx_put_image_to_window(wparam->mlx, wparam->win, image->img, 0, 0);
	mlx_key_hook(wparam->win, my_key_func,(t_param *)wparam);
	mlx_mouse_hook(wparam->win, my_mouse_func,(t_param *)wparam);
	mlx_loop(wparam->mlx);
	return (0);
}
