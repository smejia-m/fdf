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
				return (-1);
		}
		else
			i++;
	}
	return (0);
}

/*
** fonction qui verifie que la longueur de lignes soit la même
*/

static int ft_checkline(t_param *params)
{
	if(params->tmp_len != 0)
	{
		if (params->tmp_len != params->len)
			return (-1);
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

static t_param *ft_param_ini(void)
{
	t_param *params;

	if (!(params = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	params->tab = NULL;
	params->index_y = 0;
	params->index_x = 0;
	params->count_lines = 0;
	params->tmp_len = 0;
	params->len = 0;
	params->ret = 0;
	params->list = NULL;
	return (params);
}

/*
**fonction qui place les coordonnes de chaque point dans une struct t_point 
*/

static t_list *ft_toplace(t_param *param, t_list *lst)
{
	t_point *point;
	t_list *new_lst;

	param->index_x = 0;
	if(!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new_lst = NULL;
	while(param->tab[param->index_x])
	{
		point->l = ft_atoi(&param->tab[param->index_x][0]);
		point->x = param->index_x;
		point->y = param->index_y;
		param->index_x++;
		new_lst = ft_lstnew(point, sizeof(point));
		ft_lstadd(&lst, new_lst);
	}
	return (lst);
}

/*
** fonction qui transforme une liste en tableau des ints
*/
/*
static int **conlistab(t_list *list, int size_x, int size_y)
{
	int count;
	int **tab;
	t_point *point;

	count = size_y;
	*tab = (int *)malloc(sizeof(int) * size_y);
	point = 
	while(list)
	{
		tab = (int **)malloc(sizeof(int) * size_x);
		while (count > 0)
		{
			




	} 
}
*/

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

t_param *ft_reader(int fd, char *line)
{
	t_list *lst;
	t_param *parametres;
	int **tab;
	
	
	lst = NULL;
	tab = NULL;
	if(!(parametres = ft_param_ini()))
		return (NULL);
	while ((parametres->ret = get_next_line(fd, &line) > 0))
	{
		
		if(ft_checknum(line) == -1 || ft_checkline(parametres) == -1) 
			return (NULL);
		parametres->tab = ft_strsplit(line, ' ');
		parametres->tmp_len = parametres->len;
		parametres->len = count(line, ' ');
		lst = ft_toplace(parametres, lst);
		parametres->index_y++;
    }
    ft_lstrev(&lst);
    printf("index y: %d index_x : %d\n",parametres->index_y ,parametres->index_x);
   // tab = conlistab(list, parametres->index_y);
    parametres->list = lst;
    return (parametres);
}