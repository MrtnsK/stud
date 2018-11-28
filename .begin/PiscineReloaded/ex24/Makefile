# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 15:42:31 by kemartin          #+#    #+#              #
#    Updated: 2018/09/12 14:59:14 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJECTS =	ft_putchar.o \
			ft_putstr.o \
			ft_strcmp.o \
			ft_strlen.o \
			ft_swap.o

HEADER =	includes

all : $(NAME)

$(NAME) :
		gcc -c $(SRC) -I $(HEADER)
		ar -rv $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean :
		/bin/rm -rf $(OBJECTS)

fclean : clean
		/bin/rm -rf $(NAME)

re : fclean all
