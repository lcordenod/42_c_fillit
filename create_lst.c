/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:40:23 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 14:51:59 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*create_front(char **tetri, t_lst *lst)
{
	t_lst	*new;
	int		i;

	i = 0;
	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
	{
		free_lst(lst);
		free_tmp(tetri);
		exit(0);
	}
	if (!(new->data = (char**)malloc(sizeof(char*) * 5)))
	{
		free_lst(lst);
		free_tmp(tetri);
		exit(0);
	}
	while (i < 4)
	{
		new->data[i] = ft_strdup(tetri[i]);
		i++;
	}
	new->data[i] = NULL;
	new->next = NULL;
	lst = new;
	return (lst);
}

t_lst	*create_back(char **tetri, t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*new;
	int		i;

	i = -1;
	if (!(new = (t_lst*)malloc(sizeof(t_lst))) ||
			(!(new->data = (char**)malloc(sizeof(char*) * 5))))
	{
		free_lst(lst);
		free_tmp(tetri);
		free(new);
		exit(0);
	}
	while (++i < 4)
		new->data[i] = ft_strdup(tetri[i]);
	new->next = NULL;
	tmp = lst;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
	lst = tmp;
	return (lst);
}

t_lst	*reduce_list(t_lst *lst)
{
	t_lst	*begin_lst;
	char	**tmp;

	tmp = NULL;
	begin_lst = lst;
	while (lst)
	{
		tmp = lst->data;
		lst->data = tetri_min(lst);
		free_tmp(tmp);
		lst = lst->next;
	}
	lst = begin_lst;
	return (lst);
}

t_lst	*create_list(int fd)
{
	t_lst	*lst;
	t_lst	*tmp;
	char	**tetri;
	char	buff[22];
	char	**temp;

	lst = NULL;
	tetri = NULL;
	while (read(fd, buff, 21))
	{
		temp = (tetri != NULL ? tetri : NULL);
		buff[21] = '\0';
		tetri = cpy_tetri(buff, tetri);
		if (!lst)
		{
			lst = create_front(tetri, lst);
			tmp = lst;
		}
		else
			lst = create_back(tetri, lst);
		temp != 0 ? free_tmp(temp) : 0;
	}
	lst = reduce_list(tmp);
	free_tmp(tetri);
	return (lst);
}
