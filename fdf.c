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

#include "mlx.h"
#include <stdio.h> //
#include "fdf.h"
#include "stdlib.h" // mallloc

typedef struct s_param 
{
	void		*win;
	void 		*mlx;
}				t_param;



int my_key_func(int keycode, t_param *param)
{
	printf("key event %d\n", keycode);
	mlx_pixel_put(param->mlx, param->win, 300, 300, 0xFF00FF);
	return(0);
}



int main(void)
{
	int x;
	int y;
	t_param *param;

	param = (t_param *)malloc(sizeof (t_param));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 400, 400, "mlx 42");
	x = 50;
	y = 50;
	

	while (y < 150)
	{
		x = 50;
		while(x < 150)
		{
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
				x++;
		}
		y++;
	}
	mlx_key_hook(param->win, my_key_func,(t_param *)param);
	mlx_loop(param->mlx);
	return (0);
}
