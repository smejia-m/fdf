#include "fdf.h"

/*
**fonction de parsing qui verifie si les caracteres de la map sont bons
*/

static int ft_cheknum(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] < '0' || map[i] > '9')
		{
			if (map[i] == ' ' || map[i] == '-' || map[i] == '\n')
				i++;
			else
			{
				ft_putstr("error");//
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
	params->count_lines = 0;
	params->tmp_len = 0;
	params->len = 0;
	params->ret = 0;
	return (params);
}

/*
**fonction qui place les coordonnes de chaque point dans une struct t_point 
*/

static t_list *ft_toplace(char **tab, int y, t_list *lst)
{
	int i;
	t_point *point;
	t_list *new_lst;

	i = 0;
	if(!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new_lst = NULL;
	while(tab[i])
	{
		point->l = ft_atoi(&tab[i][0]);
		point->x = i + 1;
		point->y = y;
		i++;
		new_lst = ft_lstnew(point, sizeof(point));
		ft_lstadd(&lst, new_lst);
	}
	free(point);
	return (lst);
}

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

t_list *ft_reader(int fd, char *line)
{
	t_list *lst;
	t_param *params;
	if(!(params = ft_param_ini()))
		return (NULL);
	lst = NULL;
	while ((params->ret = get_next_line(fd, &line) > 0))
	{
		params->index_y++;
		if(ft_cheknum(line) == -1 || ft_checkline(params) == -1) 
			return (NULL);
		params->tab = ft_strsplit(line, ' ');
		params->tmp_len = params->len;
		params->len = count(line, ' ');
		lst = ft_toplace(params->tab, params->index_y, lst);
        free(line);
    }
    ft_lstrev(&lst);
    return (lst);
}
