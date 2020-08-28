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

INCLUDES	= $(wildcard ../*.c *.c)

.PHONY: silent show all fclean re

silent:
	@make all -s

debug: fclean
	make all CFLAGS='$(CFLAGS) -g'

all:
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME)

fclean:
	-rm -f $(NAME)
	-rm -rf $(NAME).dSYM

re: clean all
