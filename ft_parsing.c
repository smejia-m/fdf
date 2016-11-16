/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:58:10 by smejia-m          #+#    #+#             */
/*   Updated: 2016/10/11 13:58:28 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**fonction de parsing qui verifie si les caracteres de la map sont bons
*/

static int	ft_checknum(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] == ' ' || line[i] == '-' || line[i] == '\n')
				i++;
			else
			{
				ft_putstr("wrong map format");
				return (-1);
			}
		}
		else
			i++;
	}
	return (0);
}

/*
** fonction qui verifie que la longueur de lignes soit la même
*/

static int	ft_checkline(t_parse *params)
{
	if (params->tmp_len != 0)
	{
		if (params->tmp_len != params->len)
		{
			ft_putstr("wrong number of lines");
			return (-1);
		}
		else
			return (0);
	}
	return (0);
}

/*
** fonction verification d'erreur
*/

int			ft_parsing(char *line, t_parse *parametres)
{
	if (ft_checknum(line) == -1 || ft_checkline(parametres) == -1)
	{
		ft_putstr(" error\n");
		return (-1);
	}
	return (0);
}
