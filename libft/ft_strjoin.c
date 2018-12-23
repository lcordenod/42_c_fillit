/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:33:00 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/28 14:48:21 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	if (!(s1) || !(s2))
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (i + j) + 1)))
		return (0);
	while (k < i + j)
	{
		if (k < i)
			dest[k] = s1[k];
		else
			dest[k] = s2[k - i];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
