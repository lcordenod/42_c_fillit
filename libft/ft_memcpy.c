/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:27:16 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/19 17:58:26 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	dest_cpy = (unsigned char*)dest;
	src_cpy = (unsigned char*)src;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	dest = dest_cpy;
	return (dest);
}
