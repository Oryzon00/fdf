/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:26 by ajung             #+#    #+#             */
/*   Updated: 2022/01/08 00:28:40 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	printf("keycode: %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	return (0);
}
