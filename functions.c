/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:40:02 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 17:50:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**cpy_tetri(char *buff, char **tetri)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tetri = (char **)malloc(sizeof(char*) * 5)))
		return (0);
	tetri[4] = 0;
	while (i < 4)
	{
		tetri[i] = ft_strndup(buff, k);
		k += 5;
		i++;
	}
	return (tetri);
}

void			tetri_xy_pos(char **tetri, int *ytab, int *xtab)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y][x] == '#')
			{
				xtab[i] = x;
				ytab[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

char			**fill_map(char **map, int mv, int map_size, char **data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = mv / map_size;
	i = 0;
	while (data[i])
	{
		x = mv % map_size;
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] != '.')
				map[y][x] = data[i][j];
			x++;
			j++;
		}
		y++;
		i++;
	}
	return (map);
}

unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int	i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}
