/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:43:08 by sipatry           #+#    #+#             */
/*   Updated: 2018/12/17 18:01:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef	struct		s_lst
{
	char			**data;
	struct s_lst	*next;
}					t_lst;

int					check_input(int fd);
int					check_tetriminos(char	*buff);
char				**cpy_tetri(char *buff, char **tetri);
int					*ft_sort_integer_table(int *tab, int size);
int					ft_min(int *tab, int length);
int					ft_max(int *tab, int length);
int					int_len(int *tab);
int					tab_len(char **tetri);
t_lst				*create_list(int fd);
t_lst				*create_front(char **tetri, t_lst *lst);
t_lst				*create_back(char **tetri, t_lst *lst);
t_lst				*reduce_list(t_lst *lst);
char				**resized_tetri(char **square,
					char **tetri, int *y, int *x);
char				**tetri_min(t_lst *lst);
unsigned int		ft_sqrt(unsigned int nb);
int					check_tetrimino_elems_pos(char **tetri);
char				**create_map(char **map, int nb_tetri);
int					fillit(char **map, t_lst *lst, int nb, int map_size);
void				tetri_xy_pos(char **tetri, int *ytab, int *xtab);
char				**fill_map(char **map, int mv, int map_size, char **data);
int					printf_map(char **map);
char				**reset_last_pos(int mv,
					char **map, t_lst *lst, int map_size);
t_lst				*add_letter(t_lst *lst);
char				**erase_tetri(char **map,
					char **data, int mv, int map_size);
void				free_tmp(char **tmp);
void				free_lst(t_lst *lst);
char				*ft_strndup(const char *s1, int k);

#endif
