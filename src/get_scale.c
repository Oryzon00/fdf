/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:03:09 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 20:31:00 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_map_inside_window(t_all *all, int i, int j)
{
	int	check;

	check = 1;
	
	while (check)
	{
		initcoor(all, i, j);
		// if (((0 < x * all->coor.scale) && (x * all->coor.scale < 1920)) &&
		// 	((0 < y * all->coor.scale) && (y * all->coor.scale < 1080)))
		if (((0 < all->coor.c2d.x) && (all->coor.c2d.x < 1920))
			&& ((0 < all->coor.c2d.y) && (all->coor.c2d.y < 1080)))
			check = 0;
		else
			all->coor.scale -= (all->coor.scale / 100);
			//all->coor.scale -= 0.01;
	}
	return (0);
}

int	get_scale(t_all *all)
{
	all->coor.scale = 1;
	//initcoor(all, 0, 0);
	is_map_inside_window(all, 0, 0);
	printf("%f\n", all->coor.scale);
	//initcoor(all, all->map_data.size_line - 1, 0);
	is_map_inside_window(all, all->map_data.size_line - 1, 0);
	printf("%f\n", all->coor.scale);

	//initcoor(all, 0, all->map_data.nb_line - 1);
	is_map_inside_window(all, 0, all->map_data.nb_line - 1);
	printf("%f\n", all->coor.scale);
	//initcoor(all, all->map_data.size_line - 1, all->map_data.nb_line - 1);
	is_map_inside_window(all, all->map_data.size_line - 1, all->map_data.nb_line - 1);
	printf("%f\n", all->coor.scale);

}
