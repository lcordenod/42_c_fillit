/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:52:48 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/15 12:58:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**resized_tetri(char **square, char **tetri, int *y, int *x)
{
	int		i;
	int		j;

	j = 0;
	while (ft_min(y, 4) + j <= ft_max(y, 4))
	{
		i = 0;
		if (!(square[j] =
			(char*)malloc(sizeof(char) * (ft_max(x, 4) - ft_min(x, 4) + 2))))
			return (0);
		while ((ft_min(x, 4) + i) <= ft_max(x, 4))
		{
			square[j][i] = tetri[ft_min(y, 4) + j][ft_min(x, 4) + i];
			i++;
		}
		square[j][i] = '\0';
		j++;
	}
	square[j] = 0;
	return (square);
}

char	**tetri_min(t_lst *lst)
{
	char	**square;
	int		y[4];
	int		x[4];

	tetri_xy_pos(lst->data, y, x);
	if (!(square =
		(char**)malloc(sizeof(char*) * (((ft_max(y, 4) - ft_min(y, 4)) + 2)))))
	{
		free_lst(lst);
		exit(0);
	}
	if (!(square = resized_tetri(square, lst->data, y, x)))
	{
		free_lst(lst);
		exit(0);
	}
	return (square);
}
