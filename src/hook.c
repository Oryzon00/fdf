/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:04:30 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:57:44 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook2(int keycode, t_all *all)
{
	if (keycode == 97)
		decrease_gamma(all);
	else if (keycode == 100)
		increase_gamma(all);
	if (keycode == 65293)
		change_view(all);
}

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
	else
		key_hook2(keycode, all);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	(void) x;
	(void) y;
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
