/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:03:12 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/07 09:24:38 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pdlst(t_dlist *lst)//dbg func
{
	t_dlist		*cur = lst;

	while (cur)
	{
		printf("%d ",*(int *)cur->content);
		cur = cur->next;
	}
	printf("\n");
}

static void	pall(t_meta *m)
{
	printf("a: ");
	pdlst(m->a->head);
	printf("b: ");
	pdlst(m->b->head);
}

void	cl_add(t_dlist **cl, int com)
{
	int			*dai;
	t_dlist		*new;

	dai = (int *)malloc(sizeof(int));
	if (!dai)
		perror_exit("malloc failed @cl_add for dai");
	*dai = com;
	new = ft_dlstnew(dai);
	if (!new)
		perror_exit("ft_dlstnew failed @cl_add for new");
	ft_dlstins_back(cl, new);
	*cl = new;
}

void	solve(t_meta *m)
{
	int			curv;
	int			nexv;
	int			com;

	while (m->a->size)
	{
		com = 0;
		curv = cc_top(m->a);
		if (curv == m->ref[m->b->size])
			com = ps_push(m->a, m->b) | C_PB;
		else if (m->a->size > 1)
		{
			nexv = cc_next(m->a);
			if (curv > nexv)
				com = ps_swap(m->a) | C_SA;
		}
		if (!com && *(int *)m->a->tail->content == m->ref[m->b->size])
			com = ps_revrot(m->a) | C_RRA;
		if (!com)
			com = ps_rotate(m->a) | C_RA;
		cl_add(&m->cl, com);
	}
	com = m->b->size;
	while (com--)
		cl_add(&m->cl, C_PA);
	optimize(m);
}
