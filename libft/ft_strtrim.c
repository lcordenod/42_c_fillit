/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:03:15 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/20 13:36:56 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	size;

	size = 0;
	i = 0;
	if (!s)
		return (0);
	k = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '	' || s[i] == '\n')
		i++;
	if (!s[i])
		return ((ft_strdup("")));
	while (s[k - 1] == ' ' || s[k - 1] == '	' || s[k - 1] == '\n')
		k--;
	size = k - i;
	return (ft_strsub(s, i, size));
}
