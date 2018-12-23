# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sipatry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 17:44:06 by sipatry           #+#    #+#              #
#    Updated: 2018/12/17 18:08:18 by sipatry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_errors.c \
	  create_lst.c \
	  fillit.c \
	  functions.c \
	  int_sorting.c \
	  tetri_min.c \
	  tools.c \
	  main.c

INCLUDE = fillit.h 

LIBFT = libft/libft.a

OBJS= $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(LIBFT) $(OBJS) 
	gcc $(FLAGS) -include $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	make -C libft/

%.o: %.c fillit.h Makefile
	gcc $(FLAGS) -include $(INCLUDE) -o $@ -c $<

all: $(NAME)


.PHONY: clean

clean: 
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
