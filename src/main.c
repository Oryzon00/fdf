/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:33:18 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		return (0);
	read_map(av[1], &all);
	create_window(&all);
	init_origin(&all);
	print_map(&all);
	put_image_text(&all);
	hook_window(&all);
	mlx_loop(all.vars.mlx);
	return (0);
}
