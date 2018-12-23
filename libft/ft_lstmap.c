/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:16:53 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/07 10:38:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;

	if (!lst || !(dest = (t_list*)malloc(sizeof(t_list))))
		return (0);
	dest = f(lst);
	dest->next = ft_lstmap(lst->next, f);
	return (dest);
}
