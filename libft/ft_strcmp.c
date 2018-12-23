/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:03:16 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/19 17:53:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int n;

	n = 0;
	while (((unsigned char*)s1)[n] == ((unsigned char*)s2)[n] && s1[n] != '\0')
		n++;
	return (((unsigned char*)s1)[n] - ((unsigned char*)s2)[n]);
}
