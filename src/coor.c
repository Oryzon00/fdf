/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:32:17 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:22:25 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_coor *coor)
{
	coor->c3d.x = coor->c3d.x * cos(coor->gamma)
		- coor->c3d.y * sin(coor->gamma);
	coor->c3d.y = coor->c3d.x * sin(coor->gamma)
		+ coor->c3d.y * cos(coor->gamma);
}

void	initcoor(t_all *all, int i, int j)
{
	all->coor.c3d.x = 60 * i;
	all->coor.c3d.y = 60 * j;
	all->coor.c3d.z = all->map_data.map[j][i] * all->coor.z_pixel;
	rotate_z(&all->coor);
	if (all->coor.iso)
	{
		all->coor.c2d.x = all->coor.x_origin + all->coor.scale
			* ((all->coor.c3d.x - all->coor.c3d.y) * cos(0));
		all->coor.c2d.y = all->coor.y_origin + all->coor.scale
			* ((all->coor.c3d.y + all->coor.c3d.x)
				* sin(0.523599) - all->coor.c3d.z);
	}
	else
	{
		all->coor.c2d.x = all->coor.x_origin + all->coor.scale
			* all->coor.c3d.x;
		all->coor.c2d.y = all->coor.y_origin + all->coor.scale
			* all->coor.c3d.y - all->coor.c3d.z;
	}
}
