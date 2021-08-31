/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:11:57 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 16:16:47 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_swap(t_ccon *c)
{
	t_dlist		*t;

	if (c->size < 2)
		perror_exit("ps_swap called on t_conn with elem# < 2");
	t = c->head;
	c->head = c->head->next;
	t->next = c->head->next;
	if (c->head->next)
		c->head->next->prev = t;
	c->head->next = t;
	t->prev = c->head;
	c->head->prev = 0;
	return (0);
}

int	ps_push(t_ccon *from, t_ccon *to)
{
	cc_push(to, cc_top(from));
	cc_pop(from);
	return (0);
}

int	ps_revrot(t_ccon *c)
{
	t_dlist		*t;

	if (c->size > 1)
	{
		t = c->tail;
		c->tail = c->tail->prev;
		c->tail->next = 0;
		t->prev = 0;
		ft_dlstins_front(&c->head, t);
		c->head = t;
	}
	return (0);
}

int	ps_rotate(t_ccon *c)
{
	t_dlist		*t;

	if (c->size > 1)
	{
		t = c->head;
		c->head = c->head->next;
		c->head->prev = 0;
		t->next = 0;
		ft_dlstins_back(&c->tail, t);
		c->tail = t;
	}
	return (0);
}
