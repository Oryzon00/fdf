/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:06:54 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 21:01:59 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_color(t_all *all)
{
	all->mycolor.blanc = 0x00FFFFFF;
	all->mycolor.bleu = 0x005050FF;
	all->mycolor.turquoize = 0x0050FFFF;
	all->mycolor.rouge = 0x00FF5050;
	all->mycolor.vert = 0x0050FF50;
	all->mycolor.aff = all->mycolor.blanc;
}

void	change_color(int keycode , t_all *all)
{
	if (keycode == 65436)
		all->mycolor.aff = all->mycolor.blanc;
	else if (keycode == 65433)
		all->mycolor.aff = all->mycolor.bleu;
	else if (keycode == 65435)
		all->mycolor.aff = all->mycolor.turquoize;
	else if (keycode == 65430)
		all->mycolor.aff = all->mycolor.rouge;
	else if (keycode == 65437)
		all->mycolor.aff = all->mycolor.vert;
	reload_image(all);
}
