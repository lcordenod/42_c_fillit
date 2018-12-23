/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:56:49 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/21 19:23:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**dest;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	words;

	k = 0;
	i = 0;
	if (!s)
		return (0);
	words = count_words(s, c);
	if (!(dest = (char**)malloc(sizeof(char*) * (words) + 1)))
		return (0);
	while (k < words)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (!(dest[k++] = ft_strsub(s, j, i - j)))
			return (0);
	}
	dest[k] = 0;
	return (dest);
}
