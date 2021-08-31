/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:52:14 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 17:48:48 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prep_b(t_ccon *c)
{
	int	min;
	int	max;
	int	min_rp;
	int	max_rp;
	int	rc;

	max = cc_max(c);
	min = cc_min(c);
	max_rp = cc_rpos(c, max);
	min_rp = cc_rpos(c, min);
	if (ft_absi(max_rp) < ft_absi(min_rp))
		rc = max_rp;
	else
		rc = min_rp;
	if (rc < 0)
		com_n(C_RRB, -rc);
	else
		com_n(C_RB, rc);
}

static int	get_lower_bound(t_ccon *a, int n)
{
	int		v;
	int		tmp;
	t_dlist	*cur;

	if (!a->size || n > cc_max(a))
		return (n);
	v = cc_max(a);
	cur = a->head;
	while (cur)
	{
		tmp = *(int *)cur->content;
		if (tmp > n && tmp < v)
			v = tmp;
		cur = cur->next;
	}
	return (v);
}

void	push_back(t_meta *m)
{
	int	pval;
	int	ppos;

	if (m->a->size)
	{
		pval = get_lower_bound(m->a, cc_top(m->b));
		if (pval == cc_top(m->b))
			pval = cc_min(m->a);
		ppos = cc_rpos(m->a, pval);
		if (ppos < 0)
			com_n(C_RRA, -ppos);
		else
			com_n(C_RA, ppos);
	}
	com(C_PA);
}

void	sort_chunk(t_meta *m)
{
	while (m->b->size)
	{
		prep_b(m->b);
		push_back(m);
	}
}
