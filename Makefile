# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 21:22:50 by japarbs           #+#    #+#              #
#    Updated: 2019/08/04 22:57:16 by japarbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Werror -Wextra
OBJ = *.o
SRCF = *.c
INCLUDES = fillit.h

all: $(NAME)

$(NAME):
	make -C libftplus/
	gcc $(FLAGS) -o $(NAME) $(SRCF) -I $(INCLUDES) -L. libftplus/libft.a

debug:
	make -C libftplus/
	gcc -g $(FLAGS) -o $(NAME) $(SRCF) -I $(INCLUDES) -L. libftplus/libft.a
#-fsanitize=address
clean:
	/bin/rm -f $(OBJ)
	make -C libftplus/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libftplus/ fclean

re: fclean all

.PHONY: all clean fclean re
