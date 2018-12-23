/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:28:23 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/20 13:38:18 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(dest = (char *)malloc(sizeof(char) * (len) + 1)))
		return (0);
	while (i < len)
	{
		dest[i] = (char)s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
