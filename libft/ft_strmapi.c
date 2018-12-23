/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:26:21 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/19 17:46:09 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	if (s)
		i = ft_strlen(s);
	else
		return (0);
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	while (j < i)
	{
		dest[j] = (f)(j, s[j]);
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
