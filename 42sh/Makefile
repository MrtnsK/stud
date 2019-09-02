# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:34:32 by pharatyk          #+#    #+#              #
#    Updated: 2019/08/20 13:18:37 by apsaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
OBJ_DIR =			./shellobj/

SRC_AUTOK_DIR =		./shellrc/autok/
SRC_BUILTIN_DIR =	./shellrc/builtin/
SRC_CALC_DIR =		./shellrc/calc/
SRC_CORE_DIR =		./shellrc/core/
SRC_DETECTOR_DIR =	./shellrc/detector/
SRC_HISTORY_DIR =	./shellrc/history/
SRC_PARSOR_DIR =	./shellrc/parsor/
SRC_PIPE_DIR =		./shellrc/piperedir/
SRC_DOLLAR_DIR =	./shellrc/doll_expansion/
SRC_INTERNVAR_DIR =	./shellrc/internal_var/
SRC_JOB_DIR =		./shellrc/job/

SRC_AUTOK = 	autok.c\
				autok_pathter.c\
				autok_pathter_pt2.c\
				autok_pathter_pt3.c\
				autok_pathter_pt4.c\
				autok_commander.c\
				selekmoder.c\
				autok_pather.c\
				autok_pather_pt2.c\
				autok_pather_pt3.c\
				selekbasics.c\
				selekbasics_pt2.c\
				autok_inenv.c

SRC_BUILTIN =	cder.c\
				cdertools.c\
				cderpath.c\
				setenv.c\
				cderbegin.c\
				setenvstuff.c\
				cderpathclear.c\
				echoer.c\
				unsetenv.c\
				do_fc.c\
				do_fc_s.c\
				do_fc_simple.c\
				do_fc_simple_retouch.c\
				do_fc_edit.c\
				do_fc_exec.c\
				do_fc_list.c\
				do_fc_rlist.c\
				do_fc_error_check.c\
				fct_alias.c\
				fct_alias_check.c\
				fct_unalias.c\
				fct_alias_list.c\
				fct_replace_alias.c\
				typer.c\
				jobser.c\
				jobser_tools.c\
				exiter.c\
				tester.c\
				test_op.c\
				test_binary.c\
				test_unary_bcdef.c\
				test_unary_glprs.c\
				test_unary_suwxz.c\
				tester_opts.c\
				fger.c\
				bger.c

SRC_CALC =		calculator.c\
				elcaclcpower.c\
				calculatoransw.c\
				ft_elcalc.c\
				calculatorresultor.c\
				trouverror.c\
				calculatortools.c\
				calculatortools_pt2.c\
				ulticalc.c\
				ulticalc_pt2.c\
				ulticalc_pt3.c\
				ulticalclauncher.c\
				ulticalclauncher_pt2.c\
				ulticalclauncher_tools.c\
				calcomparator_tools.c\
				calcomparator.c

SRC_CORE =		fctsremplissor.c\
				inenvremplissor.c\
				pathfindertools.c\
				fctsremplissor_pt2.c\
				mainstuff.c\
				shellmain.c\
				shellmain_pt2.c\
				shellmain_pt3.c\
				shellmain_pt4.c\
				shellmain_pt5.c\
				ft_prelauncher.c\
				moder.c\
				moder_pt2.c\
				shellmainstuff.c\
				initer.c\
				initer_pt2.c\
				bg_job.c\
				init_signal.c\

SRC_DETECTOR =	activikey.c\
				activikey_pt2.c\
				hereshlag.c\
				hereshlag_pt2.c\
				inputstuffpt2.c\
				bufgetor.c\
				inputhandler.c\
				newgetbuf.c\
				bufgetortools.c\
				bufgetortools_pt2.c\
				inputhandler_pt2.c\
				newread.c\
				newread_pt2.c\
				changeprompt.c\
				changeprompt_pt2.c\
				changeprompt_pt3.c\
				inputstuff.c\
				presspap.c\
				getkey.c

SRC_HISTORY =	histdoc.c\
				histdocpt2.c\
				histdocpt3.c\
				histexpension.c\
				histexp_main.c\
				histsearch.c

SRC_PARSOR =	classor.c\
				getit.c\
				retoucheur.c\
				classortools.c\
				classortools_pt2.c\
				classortools_pt3.c\
				pars_mk2.c\
				pars_mk2_pt2.c\
				pars_mk2_pt3.c\
				pars_mk2_pt4.c\
				pars_mk2_pt5.c

SRC_PIPE = 		agreg.c\
				getredir.c\
				pipetools.c\
				redir.c\
				redir_tools.c\
				check_redirection.c\
				pipe.c\
				utils.c\
				utils2.c\
				utils3.c\
				utils4.c\
				ft_redirexe.c

SRC_DOLLAR = 	colon_exp.c\
				dollar_expansion.c\
				dollar_expansion_norme.c\
				sharp_exp.c\
				expansion_tools.c\
				percent_exp.c\
				substitution_exp.c\
				simple_dollar_tools.c\
				simple_dollar.c

SRC_INTERNVAR =	add_var.c\
				builtin_var.c\
				init_internvar.c\
				intern_var_tools.c\
				ft_getvalue.c\
				ft_parsor_var.c\
				export.c\
				export_tools.c

SRC_JOB =		init_jobctrl.c\
				job.c\
				process.c\
				launch_job.c\
				back_foreground.c\
				wait_job.c\
				on_sigchld.c\
				clear_job.c\
				builtin_arg.c\
				builtin_arg_pt2.c\
				job_tools.c\
				focus_job.c\
				status_job.c

SRCS =	$(addprefix $(SRC_AUTOK_DIR), $(SRC_AUTOK))\
		$(addprefix $(SRC_BUILTIN_DIR), $(SRC_BUILTIN))\
		$(addprefix $(SRC_CORE_DIR), $(SRC_CORE))\
		$(addprefix $(SRC_DETECTOR_DIR), $(SRC_DETECTOR))\
		$(addprefix $(SRC_HISTORY_DIR), $(SRC_HISTORY))\
		$(addprefix $(SRC_PARSOR_DIR), $(SRC_PARSOR))\
		$(addprefix $(SRC_DOLLAR_DIR), $(SRC_DOLLAR))\
		$(addprefix $(SRC_INTERNVAR_DIR), $(SRC_INTERNVAR))\
		$(addprefix $(SRC_CALC_DIR), $(SRC_CALC))\
		$(addprefix $(SRC_PIPE_DIR), $(SRC_PIPE))\
		$(addprefix $(SRC_JOB_DIR), $(SRC_JOB))

OBJ =	$(addprefix $(OBJ_DIR), $(SRC_AUTOK:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_BUILTIN:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_CORE:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_DETECTOR:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_HISTORY:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_PARSOR:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_DOLLAR:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_INTERNVAR:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_CALC:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_PIPE:.c=.o))\
		$(addprefix $(OBJ_DIR), $(SRC_JOB:.c=.o))

CC = gcc -Wall -Wextra -Werror
CFLAGS = -I ./libft/includes -I ./shellscludes
BOOST = -ltermcap
CURR_NBR = 0
NBR_SRCS = 161
COLS=$(shell tput cols)

####################_OPTIONS_########################
DINO=0
STYLE=1
CLEANSONORE=1
#####################################################

$(NAME): lib $(OBJ)
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
		printf "  \e[92mSHELL           \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [[ ($(COLS) -gt 25) && $(COLS) -lt 48 && $(STYLE) -eq 1 ]] ; then \
		printf "  \e[92m100%% \e[91m|\e[0m" ; \
		while [[ $$number -le $(REAL_PRCT) ]] ; do \
			printf "\e[102m \e[0m" ; \
			((number = number + 1)) ; \
		done ; \
		printf "\e[91m|\e[0m\n" ; \
		printf "  \e[92mSHELL           \e[91m[\e[92mDONE\e[91m]\e[0m\n" ;\
	elif [ $(STYLE) -eq 1 ] ; then \
		printf "  \e[91m|\e[0m" ; \
		while [[ $$number -le $(REAL_PRCT) ]] ; do \
			printf "\e[102m \e[0m" ; \
			((number = number + 1)) ; \
		done ; \
		printf "\e[91m|\e[0m\n" ; \
		printf "  \e[92mSHELL           \e[91m[\e[92mDONE\e[91m]\e[0m\n" ;\
	else \
		echo "Compilation OK" ; \
		echo "SHELL  COMPILED" ; \
	fi ;

	@$(CC) $(BOOST) -o $(NAME) $(OBJ) libft/libft.a

all: $(NAME)

lib:
	@make -C ./libft/

clean:
	@make clean -C ./libft/
	@rm -f $(OBJ)
	@if [[ $(STYLE) -eq 1 && $(CLEANSONORE) -eq 1 ]] ; then \
		printf "  \e[92mCLEAN           \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [ $(CLEANSONORE) -eq 1 ] ; then \
		echo "CLEANED" ; \
	fi ;

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
	@if [[ $(STYLE) -eq 1 && $(CLEANSONORE) -eq 1 ]] ; then \
		printf "  \e[92mFCLEAN          \e[91m[\e[92mDONE\e[91m]\e[0m\n" ; \
	elif [ $(CLEANSONORE) -eq 1 ] ; then \
		echo "ALL CLEANED" ; \
	fi ;

$(OBJ_DIR)%.o: $(SRC_AUTOK_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_BUILTIN_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_CALC_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_CORE_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_DETECTOR_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_HISTORY_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_PARSOR_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_PIPE_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_DOLLAR_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_INTERNVAR_DIR)%.c
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

$(OBJ_DIR)%.o: $(SRC_JOB_DIR)%.c
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

re: fclean all

.PHONY: all clean fclean re lib
