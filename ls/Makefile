# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 15:54:25 by kemartin          #+#    #+#              #
#    Updated: 2019/02/13 19:57:16 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		=	main.c \
			option.c \
			list.c \
			buf.c \
			ls.c \
			modif.c \
			param.c \
			paths.c \
			errors.c \
			leading.c \
			get_childs.c \
			printing.c \
			free.c \
			total.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./inc/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "Object done."

$(FT_LIB) :
	@make -C $(FT)
	@echo "Libft ok."

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -o $(NAME)
	@echo "Everything done."

clean :
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@echo "Objects cleaned."

fclean : clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Everything cleaned."

re: fclean all
