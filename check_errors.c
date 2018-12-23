/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:49:06 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 14:34:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetrimino_elems_pos(char **tetri)
{
	int		count;
	int		x;
	int		y;

	y = -1;
	count = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetri[y][x] == '#')
			{
				if (y && tetri[y - 1][x] == '#')
					count++;
				if (y < 3 && tetri[y + 1][x] == '#')
					count++;
				if (x && tetri[y][x - 1] == '#')
					count++;
				if (x < 3 && tetri[y][x + 1] == '#')
					count++;
			}
		}
	}
	return (count > 4);
}

int	check_tetriminos(char *buff)
{
	char	**tetri;
	int		i;
	int		count_tetri;

	count_tetri = 0;
	tetri = NULL;
	i = -1;
	if (ft_strlen(buff) == 20 && buff[19] != '\0')
		return (0);
	while (++i < 21)
	{
		if (buff[i] == '#')
			count_tetri++;
		if (buff[19] != '\n' && buff[19] != '\0')
			return (0);
		else if (((((i + 1) % 5 == 0) && buff[i] != '\n') || ((i + 1) % 5 != 0
		&& (buff[i] != '.' && buff[i] != '#'))) && i < 20)
			return (0);
	}
	if (count_tetri != 4 ||
	((tetri = cpy_tetri(buff, tetri)) && !(check_tetrimino_elems_pos(tetri))))
		return (0);
	free_tmp(tetri);
	return (1);
}

int	check_input(int fd)
{
	int		count;
	char	buff[22];
	int		count_read;
	int		last_count_read;

	if (fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	count = 0;
	while ((count_read = read(fd, buff, 21)))
	{
		buff[21] = '\0';
		if (!check_tetriminos(buff))
			return (-1);
		count++;
		last_count_read = count_read;
	}
	if (last_count_read != 20)
		return (-1);
	return (count > 26 ? -1 : count);
}
