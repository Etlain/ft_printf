# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/04/19 22:34:57 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC =   ft_printf.c ft_format.c ft_type.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
