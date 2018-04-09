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
	t_param	*parametres;

	ret = 0;
	line = NULL;
	parametres = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parametres = ft_reader(fd, line);
		if (parametres == NULL)
			return (-1);
		ret = ft_prin_struct(parametres, av[1]);
	//free(parametres);//	
	}
	else
		ret = tma_error();
	if (ret == -1)
		ft_putstr("error\n");
	return (ret);
}
