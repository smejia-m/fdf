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
#include <stdio.h>//

int my_key_func(int keycode, t_wparam *param)
{
	printf("key event %d\n", keycode); //
	mlx_pixel_put(param->mlx, param->win, 300, 300, 0xFF00FF);
	return(0);
}

int ft_graph(t_list *list)
{
	int x;
	int y;
	t_wparam *param;
	t_point *coor; //


	param = (t_wparam *)malloc(sizeof (t_wparam));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800, 600, "mlx 42");
	x = 50;
	y = 50;
	

	while(list)
	{
		coor = list->content;
		mlx_pixel_put(param->mlx, param->win, coor->x, coor->y, 0x00FFFFFF);
		printf("x = %d y = %d\n", coor->x, coor->y);//
		list = list->next;
	}
	/*while (y < 150)
	{
		x = 50;
		while(x < 150)
		{
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
				x++;
		}
		y++;
	}*/
	mlx_key_hook(param->win, my_key_func,(t_param *)param);
	mlx_loop(param->mlx);
	return (0);
}
