/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:39 by ajung             #+#    #+#             */
/*   Updated: 2022/01/09 20:49:38 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_all all;

	read_map(av[1], &all);
	create_window(&all);
	hook_window(&all);
	//print_pink_floyd(500, &all.image_data);
	mlx_loop(all.vars.mlx);
	return (0);
}

//x et y sont inverses dans mon pars.



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
// 	free_all(all);
// 	return (0);
// }
