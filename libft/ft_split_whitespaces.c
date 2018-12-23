/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 21:19:34 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/21 11:06:40 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*add_word(char *str, int j, int size)
{
	int		nb;
	char	*cpy;
	int		i;

	i = 0;
	nb = j;
	if (!(cpy = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (nb < (j + size))
	{
		cpy[i] = str[nb];
		i++;
		nb++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int		count_words(char *str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '	' && str[i] != '\n')
		{
			count++;
		}
		while (str[i] != ' ' && str[i] != '	' && str[i] != '\n' && str[i])
		{
			i++;
		}
		while (str[i] == ' ' || str[i] == '	' || str[i] == '\n')
			i++;
	}
	return (count);
}

char			**ft_split_whitespaces(char *str)
{
	int		x;
	char	**tab;
	int		j;
	int		size;

	x = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (count_words(str) + 1))))
		return (0);
	while (str[j] && x < (count_words(str)))
	{
		size = 0;
		while ((str[j] == ' ' || str[j] == '	' || str[j] == '\n') && str[j])
			j++;
		while (str[j] != ' ' && str[j] != '	' && str[j] != '\n' && str[j])
		{
			j++;
			size++;
		}
		if (!(tab[x] = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		tab[x++] = (add_word(str, (j - size), (size)));
	}
	tab[x] = 0;
	return (tab);
}
