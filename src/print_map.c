/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/11 17:26:34 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_coor(t_all *all)
{
	all->coor.x_origin = 1920 / 2;
	all->coor.y_origin = 1080 / 10;
	return (0);
}

int	get_scale(t_all *all, int x, int y)
{
	int	check;

	check = 1;
	all->coor.scale = 1;
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

int find_corners(t_all *all)
{
	all->coor.corner.x_corner1 = all->coor.x_origin;
	all->coor.corner.y_corner1 = all->coor.y_origin;
	all->coor.corner.x_corner2 = all ->coor.x_origin + 50 * all->map_data.size_line;
	all->coor.corner.y_corner2 = all->coor.y_origin;
	get_scale(all, all->coor.x_origin, all->coor.y_origin);
}
