/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:45:53 by smejia-m          #+#    #+#             */
/*   Updated: 2016/09/05 18:16:53 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 29

typedef struct		s_struct
{
	char			*tmp;
	int				fd;
	struct s_struct	*next;
}					t_stock;

int					get_next_line(const int fd, char **line);
#endif
