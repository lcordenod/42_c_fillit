/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:36:03 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 15:48:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(char **map, int nb_tetri)
{
	int		map_size;
	int		y;
	int		x;
	int		i;
	char	**tmp;

	i = 0;
	y = -1;
	tmp = map;
	map_size = ft_sqrt(nb_tetri * 4);
	if (!(map = (char **)malloc(sizeof(char*) * (map_size + 1))))
		return (0);
	while (++y < map_size)
	{
		x = -1;
		if (!(map[y] = (char *)malloc(sizeof(char) * (map_size + 1))))
			return (0);
		while (++x < map_size)
			map[y][x] = '.';
		map[y][x] = '\0';
	}
	map[y] = NULL;
	if (tmp != NULL)
		free_tmp(tmp);
	return (map);
}

int		print_map(char **map, t_lst *lst)
{
	int		i;

	i = 0;
	(void)lst;
	while (map[i])
	{
		ft_putstr(map[i]);
		free(map[i]);
		ft_putchar('\n');
		i++;
	}
	free(map[i]);
	free(map);
	return (1);
}

t_lst	*add_letter(t_lst *lst)
{
	t_lst	*tmp;
	int		i;
	int		j;
	int		k;

	k = 0;
	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (tmp->data[i])
		{
			j = -1;
			while (tmp->data[i][++j])
			{
				if (tmp->data[i][j] == '#')
					tmp->data[i][j] += 30 + k;
			}
			i++;
		}
		tmp = tmp->next;
		k++;
	}
	tmp = lst;
	return (tmp);
}

int		check_fill(int mv, char **data, char **map, int map_size)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = mv / map_size;
	i = 0;
	while (data[i])
	{
		j = 0;
		x = mv % map_size;
		if (y == map_size)
			return (0);
		while (data[i][j])
		{
			if (map[y][x] == '\0' || (map[y][x] != '.' && data[i][j] != '.'))
				return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int		fillit(char **map, t_lst *lst, int nb, int map_size)
{
	int		res;
	int		mv;
	t_lst	*tmp;

	mv = 0;
	res = 0;
	tmp = lst;
	if (!lst)
		return (print_map(map, tmp));
	else
	{
		while (mv <= nb)
		{
			if (check_fill(mv, lst->data, map, map_size))
			{
				map = fill_map(map, mv, map_size, lst->data);
				res = fillit(map, lst->next, nb, map_size);
				if (res)
					return (res);
				map = erase_tetri(map, lst->data, mv, map_size);
			}
			mv++;
		}
	}
	return (res);
}
