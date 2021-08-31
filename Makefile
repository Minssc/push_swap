# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 16:16:22 by minsunki          #+#    #+#              #
#    Updated: 2021/08/31 19:09:14 by minsunki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

FIL_M		=	push_swap.c \
				sort_chunk.c \
				command.c \
				parse.c \
				meta.c \
				ccon.c \
				ccon_util.c \
				ps_func.c \
				solve.c \
				solve_small.c

OBJ_M		=	$(FIL_M:.c=.o)

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
CFLAG_EXT	=	-Llibft -lft
RM			=	rm -f
MAKE		=	make

%.o			:	%.c
			$(CC) $(CFLAG) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJ_M)
			$(MAKE) bonus -C libft
			$(CC) $(OBJ_M) $(CFLAG) $(CFLAG_EXT) -o $(NAME)

bonus		:	$(all)

clean		:
			$(RM) $(OBJ_M)
			$(MAKE) clean -C libft

fclean		:	clean
			$(RM) $(NAME)
			$(MAKE) fclean -C libft

re			:	fclean
				$(MAKE) all

test		:	re
			$(MAKE) clean
			./$(NAME) 2 1 3 6 5 8

.PHONY		:	all clean fclean re bonus
