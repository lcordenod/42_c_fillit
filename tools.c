/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:43:21 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 15:49:09 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tmp(char **tmp)
{
	int i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
}

void	free_lst(t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	while (lst)
	{
		i = 0;
		tmp = lst->next;
		while (lst->data[i])
		{
			free(lst->data[i]);
			i++;
		}
		free(lst->data);
		free(lst);
		lst = tmp;
	}
}

char	*ft_strndup(const char *s1, int k)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (5))))
		return (0);
	while (i < 4)
	{
		dest[i] = s1[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**erase_tetri(char **map, char **data, int mv, int map_size)
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
		while (data[i][j])
		{
			if (map[y][x] == data[i][j])
				map[y][x] = '.';
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (map);
}
