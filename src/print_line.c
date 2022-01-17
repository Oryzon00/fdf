/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:52:44 by ajung             #+#    #+#             */
/*   Updated: 2022/01/17 18:26:19 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xegal(t_all *all)
{
	while (all->coor.droite.ya != all->coor.droite.yb)
	{
		my_mlx_pixel_put(all, all->coor.droite.xa,
			all->coor.droite.ya, all->mycolor.aff);
		if (all->coor.droite.ya < all->coor.droite.yb)
			all->coor.droite.ya++;
		else if (all->coor.droite.ya > all->coor.droite.yb)
			all->coor.droite.ya--;
	}
}

void	mfaible(t_all *all, double m, int b)
{
	while (all->coor.droite.xa != all->coor.droite.xb)
	{
		my_mlx_pixel_put(all, all->coor.droite.xa,
			(all->coor.droite.xa * m + 0.5 + b), all->mycolor.aff);
		if (all->coor.droite.xa < all->coor.droite.xb)
			all->coor.droite.xa++;
		else if (all->coor.droite.xa > all->coor.droite.xb)
			all->coor.droite.xa--;
	}
}

void	mfort(t_all *all, double m, int b)
{
	while (all->coor.droite.ya != all->coor.droite.yb)
	{
		my_mlx_pixel_put(all, ((all->coor.droite.ya - b) / m + 0.5),
			all->coor.droite.ya, all->mycolor.aff);
		if (all->coor.droite.ya < all->coor.droite.yb)
			all->coor.droite.ya++;
		else if (all->coor.droite.ya > all->coor.droite.yb)
			all->coor.droite.ya--;
	}
}

void	print_line(t_all *all)
{
	double	m;
	int		b;

	if (all->coor.droite.xa == all->coor.droite.xb)
	{
		xegal(all);
		return ;
	}
	m = (all->coor.droite.yb - all->coor.droite.ya);
	m /= (all->coor.droite.xb - all->coor.droite.xa);
	b = all->coor.droite.ya - (m * all->coor.droite.xa);
	if ((-1 <= m) && (m <= 1))
		mfaible(all, m, b);
	else
		mfort(all, m, b);
}
