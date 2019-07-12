# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 21:22:50 by japarbs           #+#    #+#              #
#    Updated: 2019/07/11 17:51:10 by japarbs          ###   ########.fr        #
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
	gcc $(FLAGS) -o $(NAME) $(SRCF) -I fillit.h -L. libftplus/libft.a

debug:
	make -C libftplus/
	gcc -g -fsanitize=address $(FLAGS) -o $(NAME) $(SRCF) -I fillit.h -L. libftplus/libft.a

clean:
	/bin/rm -f $(OBJ)
	make -C libftplus/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libftplus/ fclean

re: fclean all

.PHONY: all clean fclean re
