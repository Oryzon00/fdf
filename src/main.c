/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 15:18:14 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_all all;
	char	*str= "Bonjour, allo, test";

	if (ac != 2)
		return (0);
	read_map(av[1], &all);
	create_window(&all);
	init_origin(&all);
	get_scale(&all);

	print_map(&all);
	hook_window(&all);
	// init_origin(&all);
	// all.coor.droite.xA = 100;
	// all.coor.droite.yA = 100;
	// all.coor.droite.xB = 800;
	// all.coor.droite.yB = 500;
	// print_line(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win,
	all.image_data.img_ptr, 0, 0);
	mlx_string_put(all.vars.mlx, all.vars.win, 200, 200, 0x00FFFFFF, str);

	mlx_loop(all.vars.mlx);
	return (0);
}
