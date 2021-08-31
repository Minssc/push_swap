/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:20:50 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 16:13:03 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
#include <stdio.h>

# define CHUNK_SIZE 50
# define FT_DBG 0

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
	t_ccon		*a;
	t_ccon		*b;
	int			*ref;
	int			size;
}				t_meta;

void			parse(t_meta *m, int ac, char *av[]);

void			sort_chunk(t_meta *m);

void			com(int c);
void			com_n(int c, int n);

void			perror_exit(char *estr);
t_meta			*get_meta(void);

void			cc_push(t_ccon *c, int v);
void			cc_pop(t_ccon *c);
int				cc_top(t_ccon *c);
int				cc_next(t_ccon *c);
int				cc_max(t_ccon *c);

int				cc_min(t_ccon *c);
int				cc_search_front(t_ccon *c, int min, int max);
int				cc_search_back(t_ccon *c, int min, int max);
int				cc_rpos(t_ccon *c, int val);

int				ps_swap(t_ccon *c);
int				ps_push(t_ccon *from, t_ccon *to);
int				ps_rotate(t_ccon *c);
int				ps_revrot(t_ccon *c);

void			solve(t_meta *m);

#endif
