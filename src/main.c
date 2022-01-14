/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 17:09:21 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int main(int ac, char **av)
// {
// 	t_all all;
// 	char	*str= "Bonjour, allo, test";

// 	if (ac != 2)
// 		return (0);
	
// 	create_window(&all);
// 	read_map(av[1], &all);
// 	init_origin(&all);
// 	get_scale(&all);
// 	print_map(&all);
// 	hook_window(&all);

// 	mlx_put_image_to_window(all.vars.mlx, all.vars.win,
// 	all.image_data.img_ptr, 0, 0);
// 	mlx_string_put(all.vars.mlx, all.vars.win, 200, 200, 0x00FFFFFF, str);

// 	mlx_loop(all.vars.mlx);
// 	return (0);
// }


	// init_origin(&all);
	// all.coor.droite.xA = 100;
	// all.coor.droite.yA = 100;
	// all.coor.droite.xB = 800;
	// all.coor.droite.yB = 500;
	// print_line(&all);


int main(int ac, char **av)
{
	t_all	all;
	int		i;
	int 	j;
	
	read_map(av[1], &all);
	i = 0;
	while(i < all.map_data.nb_line)
	{
		j = 0;
		while (j < all.map_data.size_line)
		{
			printf("%d ", all.map_data.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return (0);
}
	
