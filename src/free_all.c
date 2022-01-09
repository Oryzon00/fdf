/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:56:02 by ajung             #+#    #+#             */
/*   Updated: 2022/01/09 20:54:47 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_all(t_all *all)
{
	int	i;

	i = 0;
	while(i < all->map_data.nb_line)
		free(all->map_data.map[i++]);
	free(all->map_data.map);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	mlx_destroy_image(all->vars.mlx, all->image_data.img_ptr);
	mlx_destroy_display(all->vars.mlx);
	free(all->vars.mlx);
	return (0);
}
