/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:45:45 by ajung             #+#    #+#             */
/*   Updated: 2022/01/14 19:15:31 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int free_split(char** ret_split)
{
	int	i;

	i = 0;
	while(ret_split[i])
	{
		free(ret_split[i]);
		i++;
	}
	free(ret_split);
}


int	*get_line(char *ret_gnl, t_all *all)
{
	int		i;
	char	**ret_split;
	int		*line;
	
	i = 0;
	ret_split = ft_split(ret_gnl, ' ');
	//dprintf(1, "split\n");
	while(ret_split[i])
		i++;
	all->map_data.size_line = i;
	line = malloc(sizeof(int) * i);
	if (!line)
		return (NULL);
	i = 0;
	while (i < all->map_data.size_line)
	{
		line[i] = ft_atoi(ret_split[i]);
		//dprintf(1, "atoi\n");
		i++;
	}
	free_split(ret_split);
	return (line);
}

int	find_nb_line(int fd)
{
	char	*ret_gnl;
	int		i;

	i = 0;
	ret_gnl = get_next_line(fd);
	while(ret_gnl)
	{
		free(ret_gnl);
		i++;
		ret_gnl = get_next_line(fd);
	}
	free(ret_gnl);
	return (i);
}

int	read_map(char *arg, t_all *all)
{
	char	*ret_gnl;
	int		**map;
	int		i;
	int		fd;
	
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		exit (0);
	//dprintf(1, "open1\n");
	all->map_data.nb_line = find_nb_line(fd);
	close(fd);
	fd = open(arg, O_RDONLY);
	//dprintf(1, "open2\n");
	ret_gnl = get_next_line(fd);
	i = 0;
	map = malloc(sizeof(int*) * all->map_data.nb_line);
	while(ret_gnl)
	{
		map[i] = get_line(ret_gnl, all);
		free(ret_gnl);
		i++;
		ret_gnl = get_next_line(fd);
		//dprintf(1, "gnl\n");
	}
	free(ret_gnl);
	all->map_data.map = map;
	return (0);
}
