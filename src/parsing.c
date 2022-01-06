/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:45:45 by ajung             #+#    #+#             */
/*   Updated: 2022/01/06 20:29:39 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line(char *ret_gnl)
{
	int		i;
	char	**ret_split;
	int		*line;
	
	i = 0;
	ret_split = ft_split(ret_gnl, ' ');
	while (ret_split[i])
	{
		line[i] = ft_atoi(ret_split[i]);
		i++;
		// i est la taille des ligne de la map
	}
	return (line);
	
}
// chopper taille des lignges
int		**read_map(int fd)
{
	char	*ret_gnl;
	int		**map;
	int		i;
	
	ret_gnl = get_next_line(fd);
	i = 0;
	while(ret_gnl)
	{
		map[i] = get_line(ret_gnl);
		i++;
		// i est le nb de ligne de la map
		ret_gnl = get_next_line(fd);
	}
	//vleur retour juste?
	return (map);

	// tout stocker dans une mega structure et j'envoie son pointeur a mes fonctions
}
