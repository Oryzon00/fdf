/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/12 18:52:53 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	init_origin(all);
	initcoor3d(all, i, j);
	switch2dto3d(all);
	get_scale(all);
	all->coor.scale = 0.7;
	while (j < all->map_data.nb_line)
	{
		i = 0;
		while(i < all->map_data.size_line)
		{
			initcoor3d(all, i, j);
			switch2dto3d(all);
			my_mlx_pixel_put(all, all->coor.scale * all->coor.c2d.x,
				all->coor.scale * all->coor.c2d.y, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}
