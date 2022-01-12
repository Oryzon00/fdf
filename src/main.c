/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/12 19:02:10 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_all all;

	all.coor.scale = 0.1;
	if (ac != 2)
		return (0);
	read_map(av[1], &all);
	create_window(&all);
	hook_window(&all);
	// printf("nb ligne =%d\n", all.map_data.nb_line);
	// printf("taille ligne =%d\n", all.map_data.size_line);
	
	print_map(&all);
	//print_pink_floyd(500, &all);
	//print_line(&all, 0, 0, 1900, 1000);
	mlx_loop(all.vars.mlx);
	return (0);
}
