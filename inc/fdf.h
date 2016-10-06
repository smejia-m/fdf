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
	int			tmp_len;
	int			len;
	int			ret;
}				t_param;

typedef struct s_wparam 
{
	void		*win;
	void 		*mlx;
}				t_wparam;

t_list			*ft_reader(int fd, char *line);
int 			ft_graph(t_list *list);
int 			my_key_func(int keycode, t_wparam *param);
#endif