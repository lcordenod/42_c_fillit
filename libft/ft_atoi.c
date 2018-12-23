/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:02:45 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/20 11:55:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int					i;
	unsigned long long	value;
	int					neg;

	i = 0;
	neg = 0;
	value = 0;
	i = ft_isspace(str, i);
	if (str[i] == '-')
		neg++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (value > 9223372036854775807 || i > 19)
		return (neg == 1 ? 0 : -1);
	if (neg == 1)
		return (-value);
	else
		return (value);
}
