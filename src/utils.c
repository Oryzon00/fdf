/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:26 by ajung             #+#    #+#             */
/*   Updated: 2022/01/11 18:57:32 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    if (((300 < x * all->coor.scale) && (x * all->coor.scale < 1920)) &&
			((0 < y * all->coor.scale) && (y * all->coor.scale < 1080)))
	{
		dst = all->image_data.addr + (y * all->image_data.line_length +
			x * (all->image_data.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	close_window(t_all *all)
{
	free_all(all);
	exit (0);
}

void	print_line(t_all *all, int xA, int yA, int xB, int yB)
{
	double	m;
	int		b;

	m = (yB - yA) / (xB - xA);
	b = 0;
	if (-1 <= m <= 1)
	{
		while (xA != xB)
		{
			my_mlx_pixel_put(all, xA, round(xA * m), 0x00FFFFFF);
			xA++;
		}
	}
	else
	{
		while (yA != yB)
		{
			my_mlx_pixel_put(all, round(yA / m), yA, 0x00FFFFFF);
			yA++;
		}
	}
}
