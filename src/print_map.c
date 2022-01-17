/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/17 18:21:39 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_line_left(t_all *all, int i, int j)
{
	initcoor(all, i, j);
	all->coor.droite.xa = all->coor.c2d.x;
	all->coor.droite.ya = all->coor.c2d.y;
	initcoor(all, i - 1, j);
	all->coor.droite.xb = all->coor.c2d.x;
	all->coor.droite.yb = all->coor.c2d.y;
	print_line(all);
}

void	trace_line_up(t_all	*all, int i, int j)
{
	initcoor(all, i, j);
	all->coor.droite.xa = all->coor.c2d.x;
	all->coor.droite.ya = all->coor.c2d.y;
	initcoor(all, i, j - 1);
	all->coor.droite.xb = all->coor.c2d.x;
	all->coor.droite.yb = all->coor.c2d.y;
	print_line(all);
}

void	print_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	initcoor(all, 0, 0);
	my_mlx_pixel_put(all, all->coor.c2d.x, all->coor.c2d.y, all->mycolor.aff);
	while (j < all->map_data.nb_line)
	{
		i = 0;
		while (i < all->map_data.size_line)
		{
			if ((i - 1) >= 0)
				trace_line_left(all, i, j);
			if ((j - 1) >= 0)
				trace_line_up(all, i, j);
			i++;
		}
		j++;
	}
}
