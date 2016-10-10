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

int my_key_func(int keycode, t_wparam *param)
{
	int x;

	x = 0;
	printf("key event %d\n", keycode); //
	while (x < 300)
	{
		mlx_pixel_put(param->mlx, param->win, 300 + x , 300, 0xFF00FF);
		x++;
	}
	return (0);
}

int my_mouse_func(int mousecode,int x, int y, t_wparam *param)
{
	printf("mouse event %d\n", mousecode);
	printf("coor x %d\n", x);
	printf("coor y %d\n", y);
		mlx_pixel_put(param->mlx, param->win, x, y, 0xFF00FF);
	return (0);
}

void my_pixel_put(t_image *image,int x, int y, t_pixel pixel)
{
	int i;

	i = ((y * image->width) + x);
	image->data[i] = pixel;
}


t_image *init_struct_img(t_wparam *wparam,int height, int width)
{
	t_image *image;
	int bits_per_pixel;
	int size_line;
	int endian;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(wparam->mlx, height, width);
	image->data = (t_pixel *)mlx_get_data_addr(image->img, &bits_per_pixel, &size_line, &endian);
	image->height = height;
	image->width = width;
	/*if (bits_per_pixel != 32 || size_line != width * 4)
	{
		return (NULL);
	}*/
	return (image);
}

int ft_graph(t_list *list, char *win_name)
{
	t_wparam *wparam;
	t_image *image;
	int x = 0;
	int y = 0;

	list = NULL; //
	wparam = (t_wparam *)malloc(sizeof (t_wparam));
	wparam->mlx = mlx_init();
	wparam->win = mlx_new_window(wparam->mlx, 800, 600, win_name);
	if(!(image = init_struct_img(wparam, 800, 600)))
		return (-1);
	while (x < image->width)
	{
		while(y < image->height)
		{
			my_pixel_put(image, x, y, 0x00FF0000);
			++y;
		}
		y = 0;
		++x;
		ft_putchar('a');
	}
	mlx_put_image_to_window(wparam->mlx, wparam->win, image->img, 0, 0);
	mlx_key_hook(wparam->win, my_key_func,(t_param *)wparam);
	mlx_mouse_hook(wparam->win, my_mouse_func,(t_param *)wparam);
	mlx_loop(wparam->mlx);
	return (0);
}
