/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:21:20 by ajung             #+#    #+#             */
/*   Updated: 2022/01/17 18:29:41 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_window(t_all *all)
{
	all->vars.mlx = mlx_init();
	if (!all->vars.mlx)
		exit (0);
	all->vars.win = mlx_new_window(all->vars.mlx, 1920, 1080, "My window");
	all->image_data.img_ptr = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->image_data.addr = mlx_get_data_addr(all->image_data.img_ptr,
			&all->image_data.bits_per_pixel, &all->image_data.line_length,
			&all->image_data.endian);
	return (0);
}

void	put_image_text(t_all *all)
{
	char	*str;

	mlx_put_image_to_window(all->vars.mlx, all->vars.win,
		all->image_data.img_ptr, 0, 0);
	str = "Bonjour, allo, test";
	mlx_string_put(all->vars.mlx, all->vars.win, 200, 200, 0x00FFFFFF, str);
}

void	reload_image(t_all *all)
{	
	mlx_destroy_image(all->vars.mlx, all->image_data.img_ptr);
	all->image_data.img_ptr = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->image_data.addr = mlx_get_data_addr(all->image_data.img_ptr,
			&all->image_data.bits_per_pixel, &all->image_data.line_length,
			&all->image_data.endian);
	put_image_text(all);
	print_map(all);
}
