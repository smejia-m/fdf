#include fdf.h

/*
** fonction de parsing qui verifire si les caracteres de la map sont bons
*/

static int ft_checknum(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (map[i] == ' ' || map[i] == '-' || map[i] == '\n')
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

static int ft_checkline(t_param parametres)
{
	if (parametres.tmp_len != 0)
	{
		if (parametres.tmp_len != parametres.len)
			return (-1);
		else
			return (0);
	}
return (0);
}

/*
**fonction qui mesure la longueur du tableau de chaine de caracteres
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

static t_param ft_param_ini(void)
{
	t_param params;

	if (!(params = (t_param )malloc(sizeof(t_param))))
		return (NULL);
	params->tab = NULL;
	params->tmp_len = 0;
	params->len = 0;
	return (params);
}

/*
** fonction qui lit la map, separe les lignes et les met dans un tableau des tableaux
*/

int **ft_reader(int fd, char *line)
{
	int ret;
	t_param parametres;
	int **tab;

	ret = 0;
	if(!(parametres = ft_param_ini()))
		return(NULL);
	tab = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (ft_checknum(line) == -1 || ft_checkline(parametres) == -1)
			return (NULL);
		parametres.tab = ft_strsplit(line, ' ');
		parametres.tmp_len = parametres.len;
		parametres->len = count(line, ' ');
		





	}

}