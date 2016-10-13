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
	int i;

	printf("image->width: %d, image->height :%d\n ", image->width, image->height);//
	i = ((y * image->width) + x);
	printf(" i : %d\n", i);//
	printf("x: %d y : %d\n",x ,y);//
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
	//printf("bits_per_pixel : %d, size_line : %d\n", bits_per_pixel, size_line);//
	/*if (bits_per_pixel != 32 || size_line != width * 4)
	{
		return (NULL);
	}*/
	return (image);
}


void ft_tracer(int xi, int yi, int xf, int yf, t_image *image)
{
	int dx;
	int dy;
	int x;
	int y;
	int index;

	dx = xf - xi;
	dy = yf - xi;
	x = xi;
	y = yi;
	my_pixel_put(image, x, y, 0x00FFFFFF);
	index = dx / 2;
	if(xf > xi && yf >= yi && (xf - xi) > (yf - yi))
	{
		while (x < xf)
		{
			//ft_putchar('q');//
			index = index + dy;
			if( index >= dx)
			{
				index = index - dx;
				y = y + 1;
			}
			my_pixel_put(image, x, y, 0x00FFFFFF);
			++x;
		}
	}
}

/*
**fonction principal qui construit le graph
*/


int ft_graph(t_param *parametres, char *win_name)
{
	t_wparam *wparam;
	t_image *image;
	t_point *point;
	//t_point *nxt_point;

	point = NULL;
	//nxt_point = NULL;
	wparam = (t_wparam *)malloc(sizeof (t_wparam));
	wparam->mlx = mlx_init();
	wparam->win = mlx_new_window(wparam->mlx, 900, 600, win_name);
	if(!(image = init_struct_img(wparam, 900,600)))
		return (-1);
	/*test
	point = parametres->list->content;
	while(parametres->list->next)
	{	
		//ft_putchar('a');//
		parametres->list = parametres->list->next;
		//ft_putchar('b');//
		nxt_point = parametres->list->content;
		//ft_putchar('c');//
		ft_tracer(point->x, point->y, nxt_point->x, nxt_point->y, image);
		//ft_putchar('d');//
		point = nxt_point;
		//ft_putchar('e');//
		//ft_putchar('\n');//
	}
	*///fin test
	while (parametres->list)
		{
		point = parametres->list->content;	
		my_pixel_put(image, (point->x - point->y) * 10 +  image->width / 2, ((point->x) + (point->y)) * 10 + image->height / 2, 0x00FF0000); //effacer le + 10
		parametres->list = parametres->list->next;
		}
	mlx_put_image_to_window(wparam->mlx, wparam->win, image->img, 0, 0);
	mlx_key_hook(wparam->win, my_key_func,(t_param *)wparam);
	mlx_mouse_hook(wparam->win, my_mouse_func,(t_param *)wparam);
	mlx_loop(wparam->mlx);
	return (0);
}
