/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:04:30 by ajung             #+#    #+#             */
/*   Updated: 2022/01/09 20:51:30 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		close_window(all);
	printf("keycode: %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_all *all)
{
	printf("keycode: %d\n", keycode);
	return (0);
}

int	hook_window(t_all *all)
{
	mlx_hook(all->vars.win, ON_DESTROY, 0, close_window, all);
	mlx_key_hook(all->vars.win, key_hook, all);
	mlx_mouse_hook(all->vars.win, mouse_hook, all);
	return (0);
}
