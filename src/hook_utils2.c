/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:58:11 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 18:43:45 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_z(t_all *all)
{
	all->coor.z_pixel++;
	reload_image(all);
}

void	decrease_z(t_all *all)
{
	all->coor.z_pixel--;
	reload_image(all);
}

void	increase_scale(t_all *all)
{
	all->coor.scale += all->coor.scale / 100;
	reload_image(all);
}

void	decrease_scale(t_all *all)
{
	all->coor.scale -= all->coor.scale / 100;
	reload_image(all);
}
