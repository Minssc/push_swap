# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 16:16:22 by minsunki          #+#    #+#              #
#    Updated: 2021/06/12 18:29:22 by minsunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

FIL_M		=	push_swap.c \
				meta.c \
				ccon.c \
				ps_func.c \
				solve.c \
				optimize.c 

OBJ_M		=	$(FIL_M:.c=.o)

CC			=	gcc
CFLAG		=	#-Wall -Wextra -Werror
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
			./$(NAME) 2 1 3 6 5 8
			echo ""
			./$(NAME) 1 2 3 4 6 5

.PHONY		:	all clean fclean re bonus
