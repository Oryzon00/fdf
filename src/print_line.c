/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:52:44 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 15:12:02 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xegal(t_all *all)
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

void	mfaible(t_all *all, double m, int b)
{
	while (all->coor.droite.xA != all->coor.droite.xB)
	{
		my_mlx_pixel_put(all, all->coor.droite.xA, (all->coor.droite.xA * m + 0.5 + b), 0x00FFFFFF);
		if (all->coor.droite.xA < all->coor.droite.xB)
			all->coor.droite.xA++;
		else if (all->coor.droite.xA > all->coor.droite.xB)
			all->coor.droite.xA--;
	}
}

void	mfort(t_all *all, double m, int b)
{
	while (all->coor.droite.yA != all->coor.droite.yB)
	{
		my_mlx_pixel_put(all, ((all->coor.droite.yA - b) / m + 0.5), all->coor.droite.yA, 0x00FFFFFF);
		if (all->coor.droite.yA < all->coor.droite.yB)
			all->coor.droite.yA++;
		else if (all->coor.droite.yA > all->coor.droite.yB)
			all->coor.droite.yA--;
	}
}

void	print_line(t_all *all)
{
	double	m;
	int		b;

	if (all->coor.droite.xA == all->coor.droite.xB)
	{
		xegal(all);
		return ;
	}
	m = (all->coor.droite.yB - all->coor.droite.yA);
	m /= (all->coor.droite.xB - all->coor.droite.xA);
	b = all->coor.droite.yA - (m * all->coor.droite.xA);
	if ((-1 <= m) && (m <= 1))
		mfaible(all, m, b);
	else
		mfort(all, m, b);
}
