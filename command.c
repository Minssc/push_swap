/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:39:34 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 16:22:58 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_com(int c)
{
	char	*cstr;

	cstr = "";
	if (c == C_SA)
		cstr = "sa";
	else if (c == C_SB)
		cstr = "sb";
	else if (c == C_PA)
		cstr = "pa";
	else if (c == C_PB)
		cstr = "pb";
	else if (c == C_RA)
		cstr = "ra";
	else if (c == C_RB)
		cstr = "rb";
	else if (c == C_RRA)
		cstr = "rra";
	else if (c == C_RRB)
		cstr = "rrb";
	ft_putendl_fd(cstr, 1);
}

void	com(int c)
{
	t_meta	*m;

	m = get_meta();
	if (c == C_SA)
		ps_swap(m->a);
	else if (c == C_SB)
		ps_swap(m->b);
	else if (c == C_PA)
		ps_push(m->b, m->a);
	else if (c == C_PB)
		ps_push(m->a, m->b);
	else if (c == C_RA)
		ps_rotate(m->a);
	else if (c == C_RB)
		ps_rotate(m->b);
	else if (c == C_RRA)
		ps_revrot(m->a);
	else if (c == C_RRB)
		ps_revrot(m->b);
	print_com(c);
}

void	com_n(int c, int n)
{
	if (n <= 0)
		return ;
	while (--n >= 0)
		com(c);
}
