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

static int ft_checknum(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] == ' ' || line[i] == '-' || line[i] == '\n')
				i++;
			else
			{
				ft_putstr("error checknum");//
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

static int ft_checkline(t_parse *params)
{
	if(params->tmp_len != 0)
	{
		if (params->tmp_len != params->len)
		{
			ft_putstr("error checkline");//
			return (-1);
		}
		else
			return (0);
	}
	return (0);
}

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
**fonction qui initisialise la structure param
*/

static t_parse *ft_parse_ini(void)
{
	t_parse *params;

	if (!(params = (t_parse *)malloc(sizeof(t_parse))))
		return (NULL);
	params->tab = NULL;
	params->index_y = 0;
	params->index_x = 0;
	params->count_lines = 0;
	params->tmp_len = 0;
	params->len = 0;
	params->ret = 0;
	return (params);
}

/*
**fonction qui place les coordonnes de chaque point dans une struct t_point 
*/

static t_list *ft_toplace(t_parse *param, t_list *lst)
{
	t_point *points;
	t_list *new_lst;
	
	param->index_x = 0;
	if(!(points = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new_lst = NULL;
	while(param->tab[param->index_x])
	{
		points->z = ft_atoi(param->tab[param->index_x]);
		points->x = param->index_x;
		points->y = param->index_y;
		param->index_x++;
		new_lst = ft_lstnew(points, sizeof(t_point));
		ft_lstadd(&lst, new_lst); 	
	}
	return (lst);
}

/*
** fonction qui transforme une liste en tableau des ints
*/

static int **conlistab(t_list *list, int size_x, int size_y)
{
	int **tab;
	t_point *point;
	int i;
	int j;

	if(!(tab = (int **)malloc(sizeof(int) * size_y)))
		return(NULL);
	point = NULL;
	i = 0;
	j = 0;
	if(!(tab[j] = (int *)malloc(sizeof(int) * size_x)))
			return(NULL);
	while(j < size_y)
	{
		if(!(tab[j] = (int *)malloc(sizeof(int) * size_x)))
			return(NULL);
		while (i < size_x)
		{
			point = list->content;
			tab[j][i] = point->z;
			++i;
			list = list->next;
		}
		i = 0;
		j++;
	}
	//test
	i = 0;
	j = 0;
	while(j < size_y)
	{
		while (i < size_x)
		{
			ft_putstr("y : ");//
			ft_putnbr(j);//
			ft_putstr(" x : ");//
			ft_putnbr(i);//
			ft_putchar('d');//
			ft_putstr(" z : ");//
			ft_putnbr(tab[j][i]);//
			ft_putchar('\n');//
			tab[j][i] = point->z;
			++i;
		}
		i = 0;
		j++;
	}

	return(tab);
}

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

t_param *ft_reader(int fd, char *line)
{
	t_list *lst;
	t_parse *parametres;
	t_param *ret;
	
	lst = NULL;
	if(!(ret = (t_param*)malloc(sizeof(t_param))))
	return (NULL); 
	if(!(parametres = ft_parse_ini()))
		return (NULL);
	while ((parametres->ret = get_next_line(fd, &line) > 0))
	{	
		if(ft_checknum(line) == -1 || ft_checkline(parametres) == -1)
		{
			ft_putstr("ERROR");
			return (NULL);
		}
		parametres->tab = ft_strsplit(line, ' ');
		parametres->tmp_len = parametres->len;
		parametres->len = count(line, ' ');
		lst = ft_toplace(parametres, lst);
		parametres->index_y++;
    }
    ft_lstrev(&lst);
	ret->height = parametres->index_y; 
	ret->width = parametres->index_x;
   	ret->tab = conlistab(lst, parametres->index_x, parametres->index_y);	
    return (ret);
}