/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:22:04 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/15 12:23:02 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(src);
	j = ft_strlen(dest);
	k = 0;
	if (size <= j)
		return (i + size);
	while (k + 1 + j < size)
	{
		dest[j + k] = src[k];
		k++;
	}
	dest[j + k] = '\0';
	return (i + j);
}
