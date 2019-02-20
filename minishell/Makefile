# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 15:54:25 by kemartin          #+#    #+#              #
#    Updated: 2019/02/20 12:14:15 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRC		=	main.c \
			cmd.c \
			function.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
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
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $< -g3
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

$(FT_LIB) :
	@make -C $(FT)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -o $(NAME)
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"
	@printf "\e[2K\e[94m[PRG]\e[0m $(NAME) done 🏎  💨 \n"

clean :
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@echo "\033[31m[DEL]\033[0m Objects cleaned ♻️"

fclean : clean
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@make -C $(FT) clean
	@make -C $(FT) fclean
	@echo "\033[33m[PRG]\033[0m Cleaning done 🚧"

re: fclean all
