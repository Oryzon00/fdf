/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:21:20 by ajung             #+#    #+#             */
/*   Updated: 2022/01/19 19:58:40 by ajung            ###   ########.fr       */
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
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	mlx_put_image_to_window(all->vars.mlx, all->vars.win,
		all->image_data.img_ptr, 0, 0);
	str = "DEPLACER MAP : FLECHES";
	str2 = "MODIFIER Z : + / -";
	str3 = "CHANGER COULEUR: 1 - 6";
	str4 = "ROTATION: A - D";
	str5 = "CHANGE VIEW : ENTER";
	mlx_string_put(all->vars.mlx, all->vars.win, 50, 50, 0x00FFFFFF, str);
	mlx_string_put(all->vars.mlx, all->vars.win, 50, 100, 0x00FFFFFF, str2);
	mlx_string_put(all->vars.mlx, all->vars.win, 50, 150, 0x00FFFFFF, str3);
	mlx_string_put(all->vars.mlx, all->vars.win, 50, 200, 0x00FFFFFF, str4);
	mlx_string_put(all->vars.mlx, all->vars.win, 50, 250, 0x00FFFFFF, str5);
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
