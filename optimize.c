/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:38:26 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/07 09:30:00 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ctos(int cmd)
{
	if (cmd == C_SA)
		return ("sa");
	else if (cmd == C_SB)
		return ("sb");
	else if (cmd == C_SS)
		return ("ss");
	else if (cmd == C_PA)
		return ("pa");
	else if (cmd == C_PB)
		return ("pb");
	else if (cmd == C_RA)
		return ("ra");
	else if (cmd == C_RB)
		return ("rb");
	else if (cmd == C_RR)
		return ("rr");
	else if (cmd == C_RRA)
		return ("rra");
	else if (cmd == C_RRB)
		return ("rrb");
	else if (cmd == C_RRR)
		return ("rrr");
	else
		return ("UNKNOWN");
}

void	print_cmd(t_dlist *cl)
{
	t_dlist	*cur;
	int		c;

	cur = ft_dlstfirst(cl);
	c = 0;
	while (cur)
	{
		printf("%s\n", ctos(*(int *)cur->content));
		fflush(stdout);
		cur = cur->next;
	}
}

static void	del_and_stitch(t_dlist **a, t_dlist **b)
{
	t_dlist		*tmp;

	if ((*a)->prev)
		(*a)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*a)->prev;
	tmp = (*a)->prev;
	ft_dlstdelone(*a, free);
	*a = tmp;
	tmp = (*b)->next;
	ft_dlstdelone(*b, free);
	*b = tmp;
}

static void	opt_tail_finalize(t_meta *m, int oc)
{
	t_dlist		*last;
	int			com;

	last = ft_dlstlast(m->cl);
	if (oc <= (m->size >> 1))
		com = C_RA;
	else
	{
		com = C_RRA;
		oc = m->size - oc;
	}
	while (oc--)
		cl_add(&last, com);
}

static void	opt_tail(t_meta *m)
{
	t_dlist		*cur;
	int			oc;

	oc = 0;
	cur = m->cl->prev;
	while (cur)
	{
		if (m->cl && (*(int *)cur->content == C_PB && \
			*(int *)m->cl->content == C_PA))
		{
			del_and_stitch(&cur, &m->cl);
			oc++;
		}
		else
		{
			m->cl = cur;
			cur = cur->prev;
		}
	}
	opt_tail_finalize(m, oc);
	return ;
	oc = (oc <= (m->size >> 1) ? oc : m->size - oc);
	if (!(cur = ft_dlstlast(m->cl)) || oc == m->size)
		return ;
	while (oc--)
		cl_add(&cur, (oc <= (m->size >> 1) ? C_RA : C_RRA));
}

void			optimize(t_meta *m)
{

	opt_tail(m);
	print_cmd(m->cl);

}
