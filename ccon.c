/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccon.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:41:06 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 16:17:23 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cc_push(t_ccon *c, int v)
{
	int			*dai;
	t_dlist		*new;

	c->size++;
	dai = (int *)malloc(sizeof(int));
	if (!dai)
		perror_exit("malloc failed @cc_push for dai");
	*dai = v;
	new = ft_dlstnew(dai);
	if (!new)
		perror_exit("ft_dlstnew failed @cc_push for new");
	ft_dlstins_front(&c->head, new);
	c->head = new;
	if (!c->tail)
		c->tail = c->head;
}

void	cc_pop(t_ccon *c)
{
	t_dlist		*tmp;

	if (!c->size)
		return ;
	c->size--;
	tmp = c->head->next;
	ft_dlstdelone(c->head, free);
	c->head = tmp;
	if (c->head)
		c->head->prev = 0;
	else
		c->tail = 0;
}

int	cc_top(t_ccon *c)
{
	if (!c->size)
		perror_exit("cc_top called on empty t_ccon");
	return (*(int *)c->head->content);
}

int	cc_next(t_ccon *c)
{
	if (c->size < 2)
		perror_exit("cc_next called on t_ccon with element# < 2");
	return (*(int *)c->head->next->content);
}

int	cc_max(t_ccon *c)
{
	int		max;
	t_dlist	*cur;

	cur = c->head;
	max = *(int *)cur->content;
	while (cur)
	{
		if (*(int *)cur->content > max)
			max = *(int *)cur->content;
		cur = cur->next;
	}
	return (max);
}
