/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:36:19 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/22 10:37:01 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef unsigned char	t_byte;
typedef unsigned int	t_pixel;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_parse
{
	char		**tab;
	int			index_y;
	int			index_x;
	int			count_lines;
	int			tmp_len;
	int			len;
	int			ret;
}				t_parse;

typedef struct	s_param
{
	int			**tab;
	int			height;
	int			width;
}				t_param;

typedef struct	s_image
{
	void		*img;
	t_pixel		*data;
	int			height;
	int			width;
	int			htile;
	int			wtile;
	int			x;
	int			y;
	t_pixel		color;
}				t_image;

typedef struct	s_wparam
{
	void		*win;
	void		*mlx;
	int			win_width;
	int			win_height;
	t_image		*image;
	t_param		*params;
}				t_wparam;

typedef struct	s_trace
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
}				t_trace;

t_param			*ft_reader(int fd, char *line);
int				ft_prin_struct(t_param *parametres, char *str);
int				my_key_func(int keycode, t_wparam *wparam);
void			ft_tracer(int xi, int yi, int xf, int yf, t_image *image);
void			my_pixel_put(t_image *image, int x, int y, t_pixel pixel);
void			ft_axey(t_param *params, t_image *image);
void			ft_axex(t_param *params, t_image *image);
int				ft_draw_img(t_wparam *wparam, t_param *params, t_image *image);
int				ft_parsing(char *line, t_parse *parametres);
t_parse			*ft_parse_ini(void);
void			trace_dx(int x, int y, t_image *image);
void			trace_dy(int x, int y, t_image *image);
void			trace_dxz(int x, int y, int **tab, t_image *image);
void			trace_dyz(int x, int y, int **tab, t_image *image);
int				ft_isocoorz(int x, int y, int z, t_image *image);
int				ft_isocoory(int x, int y, t_image *image);
int				ft_isocoorx(int x, int y, t_image *image);
t_pixel			ft_color(int z);
#endif
