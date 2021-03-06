/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:00:16 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:20:58 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_map_data
{
	int	size_line;
	int	nb_line;
	int	**map;
}				t_map_data;

typedef struct s_image_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

struct s_trgb_char
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
};

typedef union u_color
{
	int					trgb;
	struct s_trgb_char	inside;
}				t_color;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_c2d
{
	int	x;
	int	y;
}				t_c2d;

typedef struct s_c3d
{
	int	x;
	int	y;
	int	z;
}				t_c3d;

typedef struct s_droite
{
	int	xa;
	int	ya;
	int	xb;
	int	yb;
}				t_droite;

typedef struct s_coor
{
	int			x_origin;
	int			y_origin;
	int			z_pixel;
	double		scale;
	double		gamma;
	int			iso;
	t_c2d		c2d;
	t_c3d		c3d;
	t_droite	droite;
}				t_coor;

typedef struct s_mycolor
{
	int	rouge;
	int	vert;
	int	blanc;
	int	bleu;
	int	turquoize;
	int	maxime;
	int	aff;
}				t_mycolor;

typedef struct s_all
{
	t_image_data	image_data;
	t_vars			vars;
	t_map_data		map_data;
	t_coor			coor;
	t_mycolor		mycolor;	
}				t_all;

int		read_map(char *argv, t_all *all);
int		free_all(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
int		close_window(t_all *all);
int		create_window(t_all *all);
int		hook_window(t_all *all);
void	print_line(t_all *all);
int		init_origin(t_all *all);
void	initcoor(t_all *all, int i, int j);
int		get_scale(t_all *all);
void	print_map(t_all *all);
void	go_down(t_all *all);
void	go_up(t_all *all);
void	go_left(t_all *all);
void	go_right(t_all *all);
void	reload_image(t_all *all);
void	increase_z(t_all *all);
void	decrease_z(t_all *all);
void	increase_scale(t_all *all);
void	decrease_scale(t_all *all);
void	put_image_text(t_all *all);
void	init_color(t_all *all);
void	change_color(int keycode, t_all *all);
void	decrease_gamma(t_all *all);
void	increase_gamma(t_all *all);
void	change_view(t_all *all);

#endif
