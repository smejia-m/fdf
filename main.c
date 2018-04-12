/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 10:40:59 by smejia-m          #+#    #+#             */
/*   Updated: 2016/10/06 10:41:11 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	tma_error(void)
{
	ft_putstr("Error, too many arguments\n");
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;
	t_param	*parametres_global;
	
	ret = 0;
	line = NULL;
	parametres_global = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parametres_global = ft_reader(fd, line);
		ft_putstr("main 1\n");
		if (parametres_global == NULL)
		{	
			ft_putstr("error\n");
			return (-1);
		}
		ft_putstr("main 2\n");
		ret = ft_prin_struct(parametres_global, av[1]);
	}
	else
		ret = tma_error();
	if (ret == -1)
		ft_putstr("error\n");
	return (ret);
}
