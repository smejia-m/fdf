#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
#include <stdio.h> //

typedef unsigned char t_byte;
typedef unsigned int t_pixel;

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

typedef struct s_image
{
	void *img;
	t_pixel *data;
	int height;
	int width;
}				t_image;

t_list			*ft_reader(int fd, char *line);
int 			ft_graph(t_list *list, char *str);
int 			my_key_func(int keycode, t_wparam *param);
#endif