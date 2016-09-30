#include "fdf.h"
#include <stdio.h> //

/*
**fonction de parsing qui verifie si les caracteres de la map sont bons
*/

int ft_cheknum(char *map)
{
	int i;

	i = 0;
	while(map[i])
	{
		if(map[i] < '0' || map[i] > '9')
		{
			if(map[i] == ' ' || map[i] == '-' || map[i] == '\n')
			{
				i++;
			ft_putchar('a');//
			}
			else
			{
				ft_putstr("testo");//
				return(-1);
			}
		}
		i++;
	}
	return(0);
}

/*
** fonction qui lit la map separe les lignes et les mets dans une structure
*/

int ft_reader(int fd, char *line)
{
	int ret;
	t_param *param;
	t_list 	*lst; //


	ret = 0;
	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (-1);
	param->tab = NULL;
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		//if(ft_cheknum(line) != 0)
		//	return (-1);
		printf("ret : %d line : %s\n ",ret , line); //
		param->tab = ft_strsplit(line, ' ');
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
		ft_putstr("test");//
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