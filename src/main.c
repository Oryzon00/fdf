/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/10 19:42:32 by ajung            ###   ########.fr       */
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
	print_pink_floyd(500, &all.image_data);
	mlx_loop(all.vars.mlx);
	return (0);
}


//bresenham ??

//transformer 2d en 3d
// /coorx = x - y;
//coory = (x + y) / 2;

//x et y sont inverses dans mon parsing.



// int main(int ac, char **av)
// {
// 	t_all	all;
// 	int		i;
// 	int 	j;
	
// 	read_map(av[1], &all);
// 	i = 0;
// 	while(i < all.map_data.nb_line)
// 	{
// 		j = 0;
// 		while (j < all.map_data.size_line)
// 		{
// 			printf("%d ", all.map_data.map[i][j]);
// 			j++;
// 		}
// 		i++;
// 		printf("\n");
// 	}
// 	return (0);
// }
