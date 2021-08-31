/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccon_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:45:02 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 17:27:39 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cc_min(t_ccon *c)
{
	int		min;
	t_dlist	*cur;

	cur = c->head;
	min = *(int *)cur->content;
	while (cur)
	{
		if (*(int *)cur->content < min)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	return (min);
}

int	cc_search_back(t_ccon *c, int min, int max)
{
	int		i;
	int		con;
	t_dlist	*cur;

	cur = c->tail;
	i = 0;
	while (cur)
	{
		con = *(int *)cur->content;
		if (min <= con && con <= max)
			return (i);
		cur = cur->prev;
		i++;
	}
	return (-1);
}

int	cc_search_front(t_ccon *c, int min, int max)
{
	int		i;
	int		con;
	t_dlist	*cur;

	cur = c->head;
	i = 0;
	while (cur)
	{
		con = *(int *)cur->content;
		if (min <= con && con <= max)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

int	cc_rpos(t_ccon *c, int val)
{
	int	front;
	int	back;

	front = cc_search_front(c, val, val);
	back = cc_search_back(c, val, val) + 1;
	if (front < back)
		return (front);
	else
		return (-back);
}

int	cc_is_sorted(t_ccon *c)
{
	int		idx;
	t_dlist	*cur;

	cur = c->head;
	idx = -1;
	while (cur)
	{
		if (++idx != *(int *)cur->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}
