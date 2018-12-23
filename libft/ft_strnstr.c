/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:01:43 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/21 13:46:41 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (needle[i])
		i++;
	i--;
	while ((char)haystack[j])
	{
		k = 0;
		while (needle[k] == haystack[j + k])
		{
			if (k == i && (j + k) < len)
				return ((char*)&haystack[j]);
			k++;
		}
		j++;
	}
	return (0);
}
