/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/10 21:18:05 by ajung            ###   ########.fr       */
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
		if (((300 < x) && (x < 1920)) &&
			((0 < y) && (y < 1080)))
			check = 0;
		else
			all->coor.scale -= (all->coor.scale / 100);
	}
	return (0);
}

int find_corners
