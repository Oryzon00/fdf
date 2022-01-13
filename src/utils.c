/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:26 by ajung             #+#    #+#             */
/*   Updated: 2022/01/13 16:40:41 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    if (((0 < x) && (x < 1920)) && ((0 < y) && (y < 1080)))
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

void	print_line(t_all *all)
{
	double	m;
	int		b;

	if (all->coor.droite.xA == all->coor.droite.xB)
	{
		while (all->coor.droite.yA != all->coor.droite.yB)
		{
			my_mlx_pixel_put(all, all->coor.droite.xA, all->coor.droite.yA, 0x00FFFFFF);
			if (all->coor.droite.yA < all->coor.droite.yB)
				all->coor.droite.yA++;
			else if (all->coor.droite.yA > all->coor.droite.yB)
				all->coor.droite.yA--;
		}
	}
	m = (all->coor.droite.yB - all->coor.droite.yA);
	m /= (all->coor.droite.xB - all->coor.droite.xA);

	if ((-1 <= m) && (m <= 1))
	{
		while (all->coor.droite.xA != all->coor.droite.xB)
		{
			my_mlx_pixel_put(all, all->coor.droite.xA, (all->coor.droite.xA * m), 0x00FFFFFF);
			if (all->coor.droite.xA < all->coor.droite.xB)
				all->coor.droite.xA++;
			else if (all->coor.droite.xA > all->coor.droite.xB)
				all->coor.droite.xA--;
		}
	}
	
	else
	{
		while (all->coor.droite.yA != all->coor.droite.yB)
		{
			my_mlx_pixel_put(all, (all->coor.droite.yA / m), all->coor.droite.yA, 0x00FFFFFF);
			if (all->coor.droite.yA < all->coor.droite.yB)
				all->coor.droite.yA++;
			else if (all->coor.droite.yA > all->coor.droite.yB)
				all->coor.droite.yA--;
		}
	}
}

void	initcoor(t_all *all, int i, int j)
{
	all->coor.c3d.x = 60 * i;
	all->coor.c3d.y = 60 * j;
	all->coor.c3d.z = all->map_data.map[j][i] * 5;
	//c2d.x PEUT ETrE Negatif
	all->coor.c2d.x =  all->coor.x_origin + all->coor.scale * (all->coor.c3d.x - all->coor.c3d.y);
	//c2d.y PEUT ETRE Negatif
	all->coor.c2d.y = all->coor.y_origin + all->coor.scale * ((all->coor.c3d.y + all->coor.c3d.x) / 2 - all->coor.c3d.z);
}

int	init_origin(t_all *all)
{
	all->coor.x_origin = 960;
	all->coor.y_origin = 108;
	return (0);
}


int	is_map_inside_window(t_all *all, int i, int j)
{
	int	check;

	check = 1;
	
	while (check)
	{
		initcoor(all, i, j);
		// if (((0 < x * all->coor.scale) && (x * all->coor.scale < 1920)) &&
		// 	((0 < y * all->coor.scale) && (y * all->coor.scale < 1080)))
		if ((all->coor.c2d.x < 1920) && (all->coor.c2d.y < 1080))
			check = 0;
		else
			all->coor.scale -= (all->coor.scale / 100);
	}
	return (0);
}

int	get_scale(t_all *all)
{
	all->coor.scale = 1;
	//initcoor(all, 0, 0);
	is_map_inside_window(all, 0, 0);
	//initcoor(all, all->map_data.size_line - 1, 0);
	is_map_inside_window(all, all->map_data.size_line - 1, 0);
	//initcoor(all, 0, all->map_data.nb_line - 1);
	is_map_inside_window(all, 0, all->map_data.nb_line - 1);
	//initcoor(all, all->map_data.size_line - 1, all->map_data.nb_line - 1);
	is_map_inside_window(all, all->map_data.size_line - 1, all->map_data.nb_line - 1);
}
