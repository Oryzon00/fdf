/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:58:14 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:06:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_gamma(t_all *all)
{
	all->coor.gamma += 0.05;
	reload_image(all);
}

void	decrease_gamma(t_all *all)
{
	all->coor.gamma -= 0.05;
	reload_image(all);
}

void	change_view(t_all *all)
{
	if (all->coor.iso)
		all->coor.iso = 0;
	else
		all->coor.iso = 1;
	reload_image(all);
}
