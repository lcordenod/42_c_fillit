/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:47:22 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/14 19:19:45 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == d)
			return ((char*)&str[i]);
		i--;
	}
	return (0);
}
