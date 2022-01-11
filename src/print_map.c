/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:58:38 by ajung             #+#    #+#             */
/*   Updated: 2022/01/11 22:38:17 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	init_origin(all);
	get_scale(all);
	while (j < all->map_data.size_line)
	{
		i = 0;
		while(i < all->map_data.nb_line)
		{
			initcoor3d(all, i, j);
			switch2dto3d(all);
			my_mlx_pixel_put(all, all->coor.scale * all->coor.c2d.x,
				all->coor.scale * all->coor.c2d.y, 0x00ff3030);
			i++;
		}
		j++;
	}
}
