/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:10:41 by lcordeno          #+#    #+#             */
/*   Updated: 2018/12/14 17:39:08 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_sort_integer_table(int *tab, int size)
{
	int		a;
	int		b;
	int		temp;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				temp = tab[a];
				tab[a] = tab[b];
				tab[b] = temp;
			}
			b++;
		}
		a++;
	}
	return (tab);
}

int		ft_min(int *tab, int length)
{
	tab = ft_sort_integer_table(tab, length);
	return (tab[0]);
}

int		ft_max(int *tab, int length)
{
	tab = ft_sort_integer_table(tab, length);
	return (tab[length - 1]);
}

int		tab_len(char **tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
		i++;
	return (i);
}
