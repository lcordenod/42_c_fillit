/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:14:14 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/19 17:46:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;
	int		j;

	if (s)
		i = ft_strlen(s);
	else
		return (0);
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	while (j < i)
	{
		dest[j] = (f)(s[j]);
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
