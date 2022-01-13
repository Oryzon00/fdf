/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/13 20:45:07 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_all all;

	if (ac != 2)
		return (0);
	read_map(av[1], &all);
	create_window(&all);
	init_origin(&all);
	get_scale(&all);

	print_map(&all);
	hook_window(&all);
	// init_origin(&all);
	// all.coor.droite.xA = 201;
	// all.coor.droite.yA = 0;
	// all.coor.droite.xB = 201;
	// all.coor.droite.yB = 1000;
	// print_line(&all);
	mlx_loop(all.vars.mlx);
	return (0);
}
