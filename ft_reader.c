/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:32:52 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/11 11:33:22 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**fonction qui mesure la longuer du tableau de chaine de caracteres
*/

static	int		count(char const *s, char c)
{
	size_t		i;
	int			len;

	i = 1;
	len = 0;
	while (s[i] != '\0')
	{
		if ((s[i - 1] != c && s[i] == c) || (i == 0 && s[i] != c)
			|| (i == ft_strlen(s) - 1 && s[i] != c))
			len++;
		i++;
	}
	return (len);
}

/*
**fonction qui place les coordonnes de chaque point dans un tableaux de ints
*/

static int **ft_placer(t_parse *param, int **tab_int, char *line, int lin)
{
	int index;
	int len;

	index = 0;
	len = count(line, ' ');
	ft_putchar('E');//
	if (tab_int == NULL)
	{
		if (!(tab_int = (int **)malloc(sizeof(int*) * len)))
			return (NULL); 
	}
	ft_putchar('f');//
	if (!(tab_int[lin] = (int *)malloc(sizeof(int) * len)))
			return (NULL);

	ft_putchar('g');//
	while (param->tab[index])
	{
		tab_int[lin][index] = ft_atoi(param->tab[index]);
		free(param->tab[index]);//
		index++;
			ft_putchar('h');//
	}
	free(param->tab);//
		ft_putchar('I');//
	ft_putchar('\n');
return(tab_int);
}

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

t_param			*ft_reader(int fd, char *line)
{
	int 		** tab_int;
	t_parse		*parametres;
	t_param		*ret;

	tab_int = NULL;
	ft_putstr("ft_reader 1\n");
	if (!(ret = (t_param*)malloc(sizeof(t_param))))
		return (NULL);
	parametres = ft_parse_ini();
	while ((parametres->ret = get_next_line(fd, &line) > 0))
	{
		if (ft_parsing(line, parametres) == -1)
		{
			ft_strdel(&line);
			return (NULL);
		}
		parametres->tab = ft_strsplit(line, ' ');	
		parametres->len = count(line, ' ');
		parametres->tmp_len = parametres->len;
		ft_putchar('D');//
		tab_int = ft_placer(parametres, tab_int, line, parametres->index_y);
		ft_putchar('L');//
		parametres->index_y++;
		ft_strdel(&line);
	}
	ft_putstr("ft_reader 2\n");
	if (ft_parsing(line, parametres) == -1)
	{
		ft_strdel(&line);
		return (NULL);
	}
	ret->tab = tab_int;
	ret->height = parametres->index_y;
	ret->width = parametres->len;
	free(parametres);// test 0 leaks
	ft_putstr("ft_reader 3\n");
	return (ret);
}
