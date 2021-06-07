# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 16:16:22 by minsunki          #+#    #+#              #
#    Updated: 2021/06/06 18:10:18 by minsunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

FIL_M		=	push_swap.c

OBJ_M		=	$(FIL_M:.c=.o)

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
CFLAG_EXT	=	-Llibft -lft
RM			=	rm -f

%.o			:	%.c
			$(CC) $(CFLAG) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJ_M)
			make all -C libft -j8
			$(CC) $(OBJ_M) $(CFLAG) $(CFLAG_EXT) -o $(NAME)

bonus		:	$(all)

clean		:
			$(RM) $(OBJ_M)
			make clean -C libft

fclean		:	clean
			$(RM) $(NAME)
			make fclean -C libft

re			:	fclean all

.PHONY		:	all clean fclean re bonus
