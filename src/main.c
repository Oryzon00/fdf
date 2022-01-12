/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/12 21:18:51 by ajung            ###   ########.fr       */
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
	hook_window(&all);
	print_map(&all);
	//print_pink_floyd(500, &all);
	print_line(&all, 201, 0, 201, 1000);
	mlx_loop(all.vars.mlx);
	return (0);
}
