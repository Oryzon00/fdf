/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:04:30 by ajung             #+#    #+#             */
/*   Updated: 2022/01/08 00:26:33 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_window(t_all *all)
{
	mlx_hook(all->vars.win, ON_DESTROY, 0, close_window, &all->vars);
	mlx_key_hook(all->vars.win, key_hook, &all->vars);
	mlx_mouse_hook(all->vars.win, mouse_hook, &all->vars);
	return (0);
}
