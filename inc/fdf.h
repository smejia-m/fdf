#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
#include <stdio.h> //

typedef unsigned char t_byte;
typedef unsigned int t_pixel;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

// struct parse
typedef struct	s_parse
{
	char		**tab;
	int			index_y;
	int			index_x;
	int 		count_lines;
	int			tmp_len;
	int			len;
	int			ret;
}				t_parse;

typedef struct s_param
{
	int			**tab;
	int			height;
	int			width;
}				t_param;


typedef struct s_image
{
	void *img;
	t_pixel *data;
	int height;
	int width;
	int htile;
	int wtile;
	int x;
	int y;
	t_pixel color;
}				t_image; 

typedef struct s_wparam 
{
	void		*win;
	void 		*mlx;
	int			win_width;
	int 		win_height;
	t_image     *image;
	t_param		*params;
}				t_wparam;

/*typedef struct s_coo
{
	int x;
	int y;
	int xi;
	int yi;
	int xf;
	int yf;
}				t_coo;
*/


t_param			*ft_reader(int fd, char *line);
int 			ft_prin_struct(t_param *parametres, char *str);
int 			my_key_func(int keycode, t_wparam *wparam);
void 			ft_tracer(int xi, int yi, int xf, int yf, t_image *image);
void 			my_pixel_put(t_image *image, int x, int y, t_pixel pixel);
void 			ft_axey(t_param *params, t_image *image);
void			ft_axex(t_param *params, t_image *image);
int				ft_draw_img(t_wparam *wparam, t_param *params, t_image *image);
#endif