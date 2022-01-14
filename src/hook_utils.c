/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:15:34 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 20:00:09 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	go_right(t_all *all)
{
	all->coor.x_origin += 2;
	reload_image(all);
}

void	go_left(t_all *all)
{
	all->coor.x_origin -= 2;
	reload_image(all);
}

void	go_up(t_all *all)
{
	all->coor.y_origin -= 2;
	reload_image(all);
}

void	go_down(t_all *all)
{
	all->coor.y_origin += 2;
	reload_image(all);
}
