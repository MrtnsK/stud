# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 15:47:39 by kemartin          #+#    #+#              #
#    Updated: 2019/07/18 15:47:43 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_NAME =	csp_specifier.c\
			ft_memcpy.c\
			ft_strlen.c\
			dioux_specifier.c\
			ft_memdel.c\
			ft_strmap.c\
			diu_arg_detect.c\
			ft_memmove.c\
			ft_strmapi.c\
			f_specifier.c\
			ft_memset.c\
			ft_strncat.c\
			ft_atof.c\
			ft_printfd.c\
			ft_strncpy.c\
			ft_atoi.c\
			ft_putchar.c\
			ft_strndup.c\
			ft_bzero.c\
			ft_putchar_fd.c\
			ft_strnequ.c\
			ft_ftoa.c\
			ft_putendl.c\
			ft_strnew.c\
			ft_get_next_line.c\
			ft_putendl_fd.c\
			ft_strnstr.c\
			ft_isalnum.c\
			ft_putnbr.c\
			ft_strrchr.c\
			ft_isalpha.c\
			ft_putnbr_fd.c\
			ft_strsplit.c\
			ft_isascii.c\
			ft_putstr.c\
			ft_strstr.c\
			ft_isdigit.c\
			ft_putstr_fd.c\
			ft_strsub.c\
			ft_isprint.c\
			ft_strcat.c\
			ft_strtrim.c\
			ft_isspace.c\
			ft_strchr.c\
			ft_tolower.c\
			ft_itoa.c\
			ft_strclr.c\
			ft_toupper.c\
			ft_lstadd.c\
			ft_strcmp.c\
			ft_unitoa.c\
			ft_lstdel.c\
			ft_strcpy.c\
			moinsspluss.c\
			ft_lstdelone.c\
			ft_strdel.c\
			ol.c\
			ft_lstiter.c\
			ft_strdup.c\
			ox_arg_detect.c\
			ft_lstmap.c\
			ft_strequ.c\
			signs.c\
			ft_lstnew.c\
			ft_striter.c\
			silly_detect.c\
			ft_memalloc.c\
			ft_striteri.c\
			silly_detect_2.c\
			ft_memccpy.c\
			ft_strjoin.c\
			struct_tools.c\
			ft_memchr.c\
			ft_strjoin_free.c\
			tools.c\
			ft_memcmp.c\
			ft_strlcat.c\
			widthower.c\
			ft_printf.c\
			ft_strncmp.c\
			ft_abs.c\
			lifetime.c

CC = gcc -Wall -Wextra -Werror
CFLAGS = -I ./includes/

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CURR_NBR = 0
NBR_SRCS = 82
COLS=$(shell tput cols)

####################_OPTIONS_########################
DINO=0
STYLE=1
CLEANSONORE=0
#####################################################

$(NAME): $(OBJ)
	@$(eval REAL_PRCT=$(shell echo "($(COLS) / 1.5)" | bc))
	@number=1;
	@if [[ $(COLS) -gt 38 && $(DINO) -eq 1 ]] ; then \
		printf "\033[2J\e[90m                                       \n                                       \n                                       \n                    ##*########        \n                    ###########        \n                    ###########        \n                    #########          \n         ##       #######              \n         ####  ########## #            \n         ################              \n          ##############               \n             ##########                \n               ### ###                 \n               #    ##                 \e[0m\n" ; \
	fi ;

	@if [[ $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mOOOOOO  \e[92m100%% \e[91m|\e[0m" ; \
		while [[ $$number -le $(REAL_PRCT) ]] ; do \
			printf "\e[102m \e[0m" ; \
			((number = number + 1)) ; \
		done ; \
		printf "\e[91m|\e[0m\n" ; \
		printf "  \e[92mLIB             \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [[ ($(COLS) -gt 25) && $(COLS) -lt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[92m100%% \e[91m|\e[0m" ; \
		while [[ $$number -le $(REAL_PRCT) ]] ; do \
			printf "\e[102m \e[0m" ; \
			((number = number + 1)) ; \
		done ; \
		printf "\e[91m|\e[0m\n" ; \
		printf "  \e[92mLIB             \e[91m[\e[92mDONE\e[91m]\e[0m\n" ;\
	elif [ $(STYLE) -eq 1 ] ; then \
		printf "  \e[91m|\e[0m" ; \
		while [[ $$number -le $(REAL_PRCT) ]] ; do \
			printf "\e[102m \e[0m" ; \
			((number = number + 1)) ; \
		done ; \
		printf "\e[91m|\e[0m\n" ; \
		printf "  \e[92mLIB         \e[91m[\e[92mDONE\e[91m]\e[0m\n" ;\
	else \
		echo "Compilation OK" ; \
		echo "LIB COMPILED" ; \
	fi ;

	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@if [[ $(STYLE) -eq 1 && $(CLEANSONORE) -eq 1 ]] ; then \
		printf "  \e[92mCLEAN           \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [ $(CLEANSONORE) -eq 1 ] ; then \
		echo "CLEANED" ; \
	fi ;

fclean: clean
	@rm -f $(NAME)
	@if [[ $(STYLE) -eq 1 && $(CLEANSONORE) -eq 1 ]] ; then \
		printf "  \e[92mFCLEAN          \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [ $(CLEANSONORE) -eq 1 ] ; then \
		echo "ALL CLEANED" ; \
	fi ;

re: fclean all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(eval CURR_NBR=$(shell echo "$(CURR_NBR) + 1" | bc))
	@$(eval TRUNC_PERCENT=$(shell echo "($(COLS) * $(CURR_NBR)) / $(NBR_SRCS) / 1.5" | bc))
	@$(eval PERCENT=$(shell echo "(100 * $(CURR_NBR)) / $(NBR_SRCS)" | bc))
	@$(eval REAL_PRCT=$(shell echo "($(COLS) / 1.5)" | bc))

	@if [[ $(shell echo "$(CURR_NBR) % 2" | bc) -eq 0 && $(COLS) -gt 38 && $(DINO) -eq 1 ]] ; then \
		printf "\033[2J                                       \n\e[97m                                       \n\e[97m                                       \n\e[97m                                       \n\e[97m       -         -   \e[90m##*#######        \n\e[97m             -       \e[90m##########        \n\e[97m                 -   \e[90m#####.....        \n\e[97m       -   \e[90m#        #####              \n\e[97m           \e[90m##    ##########            \n\e[97m      -     \e[90m##############             \n\e[97m         -  \e[90m#############              \n\e[97m              \e[90m#########                \n\e[97m                \e[90m##  ##                 \n\e[97m                     \e[90m#                 \e[0m\n" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 2" | bc) -eq 1 && $(COLS) -gt 38 && $(DINO) -eq 1 ]] ; then \
		printf "\033[2J                                       \n\e[97m                                       \n\e[97m                                       \n\e[97m                                       \n\e[97m         -          \e[90m##*#######         \n\e[97m               -    \e[90m##########         \n\e[97m       -   -        \e[90m#####.....         \n\e[97m          \e[90m#        #####               \n\e[97m       -  \e[90m##    ##########             \n\e[97m          \e[90m##############               \n\e[97m     -     \e[90m#############               \n\e[97m       -     \e[90m#########                 \n\e[97m               \e[90m###  ##                 \n\e[97m               \e[90m#                       \e[0m\n" ; \
	elif [ $(DINO) -eq 1 ] ; then \
		printf "\033[2J" ; \
	fi ;

	@if [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 5 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mOOOOO\e[96m0\e[0m" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 0 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[96m0\e[90mOOOOO\e[0m" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 1 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mO\e[96m0\e[90mOOOO\e[0m" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 2 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mOO\e[96m0\e[90mOOO\e[0m" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 3 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mOOO\e[96m0\e[90mOO\e[0m" ; \
	elif [[ $(shell echo "$(CURR_NBR) % 6" | bc) -eq 4 && $(COLS) -gt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[90mOOOO\e[96m0\e[90mO\e[0m" ; \
	fi ;

	@if [[ $(COLS) -gt 25 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[92m%3d%% \e[91m|\e[0m" `echo "$(PERCENT)" | bc` ; \
	elif [ $(STYLE) -eq 1 ] ; then \
		printf "  \e[91m|\e[0m" ; \
	fi ;

	@number=1; \
	while [[ $$number -le $(REAL_PRCT) ]] ; do \
	if [[ $$number -le $(TRUNC_PERCENT) && $(STYLE) -eq 1 ]]; then \
		printf "\e[102m \e[0m" ; \
	elif [ $(STYLE) -eq 1 ] ; then\
		printf " " ; \
	fi ; \
	((number = number + 1)) ; \
	done ;

	@if [ $(STYLE) -eq 1 ] ; then \
		printf " \e[91m|\e[0m\r" ; \
	elif [[ $(STYLE) -eq 0 && $(shell echo "$(CURR_NBR) % 3" | bc) -eq 0 ]]; then \
		printf "Compiling .  \r" ; \
	elif [[ $(STYLE) -eq 0 && $(shell echo "$(CURR_NBR) % 3" | bc) -eq 1 ]]; then \
		printf "Compiling .. \r" ; \
	elif [[ $(STYLE) -eq 0 && $(shell echo "$(CURR_NBR) % 3" | bc) -eq 2 ]]; then \
		printf "Compiling ...\r" ; \
	fi ;

	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: all clean fclean re
