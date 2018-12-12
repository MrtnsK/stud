# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 14:21:57 by kemartin          #+#    #+#              #
#    Updated: 2018/12/12 18:29:14 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= main.c \
		  events.c \
		  pixel.c \
		  setup.c \
		  fractal.c \
		  mouse.c \
		  thread.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc -Ofast -flto -march=native
CFLAGS	= -Wall -Wextra -Werror

MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L ./minilibx -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./inc/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "Object done."

$(FT_LIB):
	@make -C $(FT)
	@echo "Libft ok."

$(MLX_LIB):
	@make -C $(MLX)
	@echo "MiniLibX ok."

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME) -fsanitize=address -g3
	@echo "Everything done."

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Everything cleaned."

re: fclean all
