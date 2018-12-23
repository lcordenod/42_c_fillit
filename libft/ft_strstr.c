/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:05:06 by sipatry           #+#    #+#             */
/*   Updated: 2018/11/21 09:51:03 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (needle[i])
		i++;
	i--;
	while (haystack[j])
	{
		k = 0;
		while (needle[k] == haystack[j + k])
		{
			if (k == i)
				return ((char*)&haystack[j]);
			k++;
		}
		j++;
	}
	return (0);
}
