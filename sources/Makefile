# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/06/17 00:00:29 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC =   ft_printf.c ft_format.c ft_type.c write_nbr.c ft_is.c ft_wp.c\
	fill_zero.c add_width.c change_color.c ft_sc.c no_print.c ft_type.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(FLAGS) $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
