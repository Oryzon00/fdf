/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:26 by ajung             #+#    #+#             */
/*   Updated: 2022/01/11 22:35:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    if (((300 < x * all->coor.scale) && (x * all->coor.scale < 1920)) &&
			((0 < y * all->coor.scale) && (y * all->coor.scale < 1080)))
	{
		dst = all->image_data.addr + (y * all->image_data.line_length +
			x * (all->image_data.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	close_window(t_all *all)
{
	free_all(all);
	exit (0);
}

void	print_line(t_all *all, int xA, int yA, int xB, int yB)
{
	double	m;
	int		b;

	m = (yB - yA) / (xB - xA);
	b = 0;
	if (-1 <= m <= 1)
	{
		while (xA != xB)
		{
			my_mlx_pixel_put(all, xA, round(xA * m), 0x00FFFFFF);
			xA++;
		}
	}
	else
	{
		while (yA != yB)
		{
			my_mlx_pixel_put(all, round(yA / m), yA, 0x00FFFFFF);
			yA++;
		}
	}
}

void	switch2dto3d(t_all *all)
{
	all->coor.c2d.x = all->coor.c3d.x - all->coor.c3d.z;
	all->coor.c2d.y = all->coor.c3d.y - all->coor.c3d.z;
}

void	initcoor3d(t_all *all, int i, int j)
{
	all->coor.c3d.x = all->coor.x_origin + 50 * i;
	all->coor.c3d.y = all->coor.y_origin + 50 * j;
	all->coor.c3d.z = all->map_data.map[j][i] * 50;
}

int	init_origin(t_all *all)
{
	all->coor.x_origin = 1920 / 2;
	all->coor.y_origin = 1080 / 10;
	return (0);
}

int	is_map_inside_window(t_all *all, int x, int y)
{
	int	check;

	check = 1;
	
	while (check)
	{
		if (((300 < x * all->coor.scale) && (x * all->coor.scale < 1920)) &&
			((0 < y * all->coor.scale) && (y * all->coor.scale < 1080)))
			check = 0;
		else
			all->coor.scale -= (all->coor.scale / 100);
	}
	return (0);
}

int get_scale(t_all *all)
{
	all->coor.scale = 1;
	//J'envoie des coordonnes en 3d et pas 2d
	//point origine = corner 1
	
	is_map_inside_window(all, all->coor.c2d.x, all->coor.c2d.x);


	
	// //corner2
	// is_map_inside_window(all, all->coor.x_origin + 50 * all->map_data.size_line,
	// 	all->coor.y_origin);
	// //corner3
	// is_map_inside_window(all, all->coor.x_origin,
	// 	all->coor.y_origin + 50 *all->map_data.nb_line);
	// //corner4
	// is_map_inside_window(all, all->coor.x_origin + 50 * all->map_data.size_line,
	// 	all->coor.y_origin + 50 *all->map_data.nb_line);

	
	
}
