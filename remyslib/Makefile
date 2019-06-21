# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jetownle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 20:49:38 by jetownle          #+#    #+#              #
#    Updated: 2019/06/20 20:21:02 by jetownle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME = libft.a 
 
 PART1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
          ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
          ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
          ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
          ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
          ft_isprint.c ft_toupper.c ft_tolower.c
 
 PART2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
         ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
         ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
         ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
         ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

 BONUS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
           ft_lstmap.c

 EXTRA = ft_isupper.c ft_islower.c ft_strndup.c ft_intlen.c ft_findsubstrs.c \
         ft_findsubstrlen.c get_next_line.c

 HDRS = libft.h get_next_line.h

 FILES = $(PART1) $(PART2) $(BONUS) $(EXTRA)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HDRS) -c $(FILES)
	ar -r libft.a *.o
	ranlib libft.a

clean:
	rm -rf *.o
	rm -rf libft.h.gch

fclean: clean
	rm -rf libft.a

re: fclean all

debug:
	gcc -Wall -Wextra -Werror -g -I $(HDRS) -c $(FILES)
	ar -r libft.a *.o
	ranlib libft.a
