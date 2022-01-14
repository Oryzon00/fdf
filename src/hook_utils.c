/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:15:34 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 18:31:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	go_right(t_all *all)
{
	all->coor.x_origin += 2;
	reload_image(all);
}

void	go_left(t_all *all)
{
	all->coor.x_origin -= 2;
	reload_image(all);
}

void	go_up(t_all *all)
{
	all->coor.y_origin -= 2;
	reload_image(all);
}

void	go_down(t_all *all)
{
	all->coor.y_origin += 2;
	reload_image(all);
}

void	reload_image(t_all *all)
{
	char	*str= "Bonjour, allo, test";
	
	mlx_destroy_image(all->vars.mlx, all->image_data.img_ptr);
	all->image_data.img_ptr = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->image_data.addr = mlx_get_data_addr(all->image_data.img_ptr,
		&all->image_data.bits_per_pixel, &all->image_data.line_length, 
		&all->image_data.endian);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win,
		all->image_data.img_ptr, 0, 0);
	mlx_string_put(all->vars.mlx, all->vars.win, 200, 200, 0x00FFFFFF, str);
	print_map(all);
}
