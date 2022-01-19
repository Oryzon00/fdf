/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:26 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:01:44 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	if (((0 < x) && (x < 1920)) && ((0 < y) && (y < 1080)))
	{
		dst = all->image_data.addr + (y * all->image_data.line_length
				+ x * (all->image_data.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	close_window(t_all *all)
{
	free_all(all);
	exit (0);
}

int	init_origin(t_all *all)
{
	all->coor.x_origin = 960;
	all->coor.y_origin = 108;
	all->coor.z_pixel = 5;
	all->coor.gamma = 0;
	all->coor.iso = 1;
	get_scale(all);
	init_color(all);
	return (0);
}
