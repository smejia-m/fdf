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
	while(x < 300)
	{
		mlx_pixel_put(param->mlx, param->win, 300 + x , 300, 0xFF00FF);
		x++;
	}
	return(0);
}

int ft_graph(t_list *list, char *win_name)
{
	t_wparam *param;
	t_point *coor;
	//t_point *nextcoor;
	int dx;
	int dy;

	param = (t_wparam *)malloc(sizeof (t_wparam));
	param->mlx = mlx_init();
	param->img = mlx_new_image(param->mlx, 800, 600);
	param->win = mlx_new_window(param->mlx, 800, 600, win_name);
	//coor = list->content;
	while(list)
	{
		//nextcoor = list->content;
	//	printf("coor->x : %d\n", coor->x); //
	//	printf("coor->y : %d\n", coor->y); //
		dx = coor->x - coor->y + 10;
		dy = (coor->x + coor->y);
		coor = list->content;//
		mlx_pixel_put(param->mlx, param->img, dx * 10, dy * 10, 0x00FFFFFF);
	//	coor = nextcoor;
		list = list->next;
	}
	dx = coor->x - coor->y + 10;
	dy = coor->x + coor->y;
	mlx_pixel_put(param->mlx, param->img, dx * 10, dy * 10, 0x00FFFFFF);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 30, 30);
	mlx_key_hook(param->win, my_key_func,(t_param *)param);
	mlx_loop(param->mlx);
	return (0);
}
