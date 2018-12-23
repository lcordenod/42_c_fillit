/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:34:46 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/21 13:45:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	while (str[i])
	{
		if (str[i] == d)
			return ((char*)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char*)&str[i]);
	return (0);
}
