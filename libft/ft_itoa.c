/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:19:05 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/30 15:26:30 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	j = (n < 0 ? -n : n);
	i = (n < 0 ? 2 : 1);
	while (j /= 10)
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	dest[i] = '\0';
	j = (n < 0 ? -n : n);
	dest[--i] = j % 10 + '0';
	while (j /= 10)
		dest[--i] = j % 10 + '0';
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
