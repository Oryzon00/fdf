/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:04:30 by ajung             #+#    #+#             */
/*   Updated: 2022/01/18 20:21:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		close_window(all);
	else if (keycode == 65363)
		go_right(all);
	else if (keycode == 65364)
		go_down(all);
	else if (keycode == 65361)
		go_left(all);
	else if (keycode == 65362)
		go_up(all);
	else if (keycode == 65451)
		increase_z(all);
	else if (keycode == 65453)
		decrease_z(all);
	else if (65429 <= keycode && keycode <= 65437)
		change_color(keycode, all);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	if (keycode == 4)
		increase_scale(all);
	else if (keycode == 5)
		decrease_scale(all);
	return (0);
}

int	hook_window(t_all *all)
{
	mlx_hook(all->vars.win, ON_DESTROY, 0, close_window, all);
	mlx_hook(all->vars.win, ON_KEYDOWN, 1L << 0, key_hook, all);
	mlx_mouse_hook(all->vars.win, mouse_hook, all);
	return (0);
}
