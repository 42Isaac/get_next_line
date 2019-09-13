# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iperez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 06:24:02 by iperez            #+#    #+#              #
#    Updated: 2019/06/19 06:24:04 by iperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= gnl
CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= $(wildcard *.c) libft/libft.a

.PHONY: silent show all clean fclean re

silent:
	@make all -s

debug:
	make all CFLAGS='$(CFLAGS) -g'

all:
	$(MAKE) all -C libft
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME)

clean:
	-$(MAKE) clean -C libft -s

fclean:
	-$(MAKE) clean -C libft -s
	-rm -f $(NAME)
	-rm -f -r $(NAME).dSYM

re: clean all
