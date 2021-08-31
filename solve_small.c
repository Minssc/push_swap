/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:12:18 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 19:42:00 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ccon *cont)
{
	const int	a = *(int *)cont->head->content;
	const int	b = *(int *)cont->head->next->content;
	const int	c = *(int *)cont->head->next->next->content;

	if (a < b && b > c && c > a)
	{
		com(C_SA);
		com(C_RA);
	}
	else if (a > b && b < c && c > a)
		com(C_SA);
	else if (a < b && b > c && c < a)
		com(C_RRA);
	else if (a > b && b > c && c < a)
	{
		com(C_SA);
		com(C_RRA);
	}
	else if (a > b && b < c && c < a)
		com(C_RA);
}

static void	sort_small(t_meta *m)
{
	int	rp;

	com_n(C_PB, m->size - 3);
	sort_three(m->a);
	while (m->b->size)
		push_back(m);
	rp = cc_rpos(m->a, 0);
	if (rp < 0)
		com_n(C_RRA, -rp);
	else
		com_n(C_RA, rp);
}

void	solve_small(t_meta *m)
{
	if (m->size == 2)
		com(C_SA);
	else if (m->size == 3)
		sort_three(m->a);
	else
		sort_small(m);
}
