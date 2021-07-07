/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:20:50 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/07 09:19:59 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
#include <stdio.h>

# define C_SA 1
# define C_SB 2
# define C_SS 3
# define C_PA 4
# define C_PB 5
# define C_RA 6
# define C_RB 7
# define C_RR 8
# define C_RRA 9
# define C_RRB 10
# define C_RRR 11

typedef struct s_ccon
{
	t_dlist		*head;
	t_dlist		*tail;
	int			size;
}				t_ccon;

typedef struct s_meta
{
	t_dlist		*cl;
	t_ccon		*a;
	t_ccon		*b;
	int			*ref;
	int			size;
}				t_meta;

void			perror_exit(char *estr);
t_meta			*get_meta(void);

void			cc_push(t_ccon *c, int v);
void			cc_pop(t_ccon *c);
int				cc_top(t_ccon *c);
int				cc_next(t_ccon *c);

int				ps_swap(t_ccon *c);
int				ps_push(t_ccon *from, t_ccon *to);
int				ps_rotate(t_ccon *c);
int				ps_revrot(t_ccon *c);

char			*ctos(int cmd);
void			cl_add(t_dlist **cl, int com);
void			solve(t_meta *m);
void			optimize(t_meta *m);

#endif
