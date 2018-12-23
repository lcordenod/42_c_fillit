/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:42:21 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 14:42:08 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		display_error(int ac, char **av)
{
	int fd;
	int	nb_tetri;

	nb_tetri = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if ((nb_tetri = check_input(fd)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	return (nb_tetri);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	t_lst	*lst;
	char	**map;
	int		map_size;

	nb_tetri = 0;
	map_size = 0;
	map = NULL;
	if (!(nb_tetri = display_error(ac, av)))
		return (0);
	fd = open(av[1], O_RDONLY);
	lst = create_list(fd);
	map = create_map(map, nb_tetri);
	map ? map_size = ft_sqrt(nb_tetri * 4) : free_lst(lst);
	lst = add_letter(lst);
	while (!(fillit(map, lst, (map_size * map_size), map_size)))
	{
		nb_tetri++;
		map = create_map(map, nb_tetri);
		map_size = ft_sqrt(nb_tetri * 4);
	}
	free_lst(lst);
	close(fd);
	return (0);
}
