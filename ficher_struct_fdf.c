#include "fdf.h"
#include <stdio.h> //

/*
**fonction de parsing qui verifie si les caracteres de la map sont bons
*/

int ft_cheknum(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] < '0' || map[i] > '9')
		{
			//ft_putchar('b');//
			if (map[i] == ' ' || map[i] == '-' || map[i] == '\n')
			{

				i++;
			//ft_putchar('a');//
			}
			else
			{
				ft_putstr("error");//
				return (-1);
			}
		}
		else
		{

		//ft_putchar('c');//
		i++;
		}
	}
	return (0);
}

/*
**fonction qui initisialise la structure
*/

t_point *ft_point_ini(void)
{
	t_point *point;
	
	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	return (point);
}

t_param *ft_param_ini(void)
{
	t_param *params;

	if (!(params = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	params->tab = NULL;
	params->index_y = 0;
	params->index_x = 0;
	params->count_lines = 0;
	return (params);
}

/*
**fonction qui place dans une structure les coordones 
*/

t_point *ft_toplace(char **tab, int y)
{
	int i;
	t_point *point;

	i = 0;
	if(!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	while(tab[i])
	{
		point->l = ft_atoi(&tab[i][0]);
		point->x = i + 1;
		point->y = y;
		i++;
	}
	return (point);
}

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

int ft_reader(int fd, char *line)
{
	int ret;
	t_list *lst;
	t_list *new_lst;
	t_point *coor;
	t_param *params;

	ret = 0;
	if(!(params = ft_param_ini()))
		return (-1);
	coor = NULL;
	lst = NULL;
	new_lst = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		params->index_y++;
		if(ft_cheknum(line) == -1)
			return (-1);
		printf("ret : %d line : %s\n ",ret , line); //
		params->tab = ft_strsplit(line, ' ');
		coor = ft_toplace(params->tab, params->index_y);
		new_lst = ft_lstnew(coor, sizeof(coor));
		ft_lstadd(&lst, new_lst);
        free(line);
    }
    return(0);
}

/*
**fonction reader qui lit le ficher ouvert dans le main et qui le place dans une structure
*/



/*
**la fonction main reçoit un ficher map qui doit etre ouvert
*/

int main (int ac, char **av)
{
	int fd;
	int ret;
	char *line;

	fd = 0;
	ret = 0;
	line = NULL;
	if (ac == 2)
	{
		//ft_putstr("test");//
		fd = open(av[1], O_RDONLY);
		ret = ft_reader(fd, line);
	}
	else
	{ 
		return (0);
		ft_putstr("error\n");
	}
	return(ret);
}