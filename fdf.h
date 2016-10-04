#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct	s_point
{
	int x;
	int y;
	int l;
}				t_point;

typedef struct	s_param
{
	char		**tab;
	int			index_y;
	int 		index_x;
	int 		count_lines;
}				t_param;



#endif