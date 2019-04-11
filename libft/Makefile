# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iperez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 13:02:20 by iperez            #+#    #+#              #
#    Updated: 2019/02/04 13:33:59 by iperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra
AT			:= @

FILES		= $(wildcard libc/*.c additional/*.c bonus/*.c personal/*.c)

OBJ			= $(FILES:%.c=%.o)

.PHONY: clean fclean all re show

all: $(NAME)

$(NAME): $(OBJ)
	$(AT)ar -rcs $(NAME) $(OBJ)

(OBJ): $(FILES)
	$(AT)gcc $(CFLAGS) $(FILES)

clean:
	$(AT)rm -f $(OBJ)

fclean: clean
	$(AT)rm -f $(NAME)

re: fclean all

show:
	make AT=