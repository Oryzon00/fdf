/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:00:16 by ajung             #+#    #+#             */
/*   Updated: 2022/01/11 18:52:12 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


typedef	struct s_map_data
{
	int	size_line;
	int	nb_line;
	int	**map;
}				t_map_data;

typedef struct	s_image_data 
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

struct trgb_char
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char t;
};

typedef union	u_color
{
    int					trgb;
    struct trgb_char	inside;
}    			t_color;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef	struct s_corner
{
	int	x_corner1;
	int	y_corner1;
	int	x_corner2;
	int	y_corner2;
	int	x_corner3;
	int	y_corner3;
	int	x_corner4;
	int	y_corner4;
}				t_corner;


typedef struct	s_coor
{
	int			x_origin;
	int			y_origin;
	double		scale;
	t_corner	corner;
}				t_coor;


typedef struct	s_all
{
	t_image_data	image_data;
	t_vars			vars;
	t_map_data		map_data;
	t_coor			coor;
	
}				t_all;


int		read_map(char *argv, t_all *all);
int		free_all(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
int		close_window(t_all *all);
int		create_window(t_all *all);
int		hook_window(t_all *all);
void	print_line(t_all *all, int xA, int yA, int xB, int yB);


//A supprimer
void	print_pink_floyd(int x, t_all *all);

#endif
