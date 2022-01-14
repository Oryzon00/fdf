/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 15:29:13 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	initcoor(all, 0, 0);
	my_mlx_pixel_put(all, all->coor.c2d.x, all->coor.c2d.y, 0x00FFFFFF);
	while (j < all->map_data.nb_line)
	{
		i = 0;
		while(i < all->map_data.size_line)
		{
			//initcoor(all, i, j);
			//my_mlx_pixel_put(all, all->coor.c2d.x, all->coor.c2d.y, 0x00FF3030);
			if ((i - 1) >= 0)
			{
				initcoor(all, i, j);
				all->coor.droite.xA = all->coor.c2d.x;
				all->coor.droite.yA = all->coor.c2d.y;
				initcoor(all, i - 1, j);
				all->coor.droite.xB = all->coor.c2d.x;
				all->coor.droite.yB = all->coor.c2d.y;
				print_line(all);
			}
			if ((j - 1) >= 0)
			{
				initcoor(all, i, j);
				all->coor.droite.xA = all->coor.c2d.x;
				all->coor.droite.yA = all->coor.c2d.y;
				initcoor(all, i, j - 1);
				all->coor.droite.xB = all->coor.c2d.x;
				all->coor.droite.yB = all->coor.c2d.y;
				print_line(all);

			}
			i++;
			
		}
		j++;
	}
}
