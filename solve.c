/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:03:12 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 17:32:52 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_element(t_meta *m, int min, int max)
{
	int	front;
	int	back;

	front = cc_search_front(m->a, min, max);
	back = cc_search_back(m->a, min, max) + 1;
	if (front < back)
		com_n(C_RA, front);
	else
		com_n(C_RRA, back);
	com(C_PB);
}

static void	push_chunk(t_meta *m, int min, int max)
{
	int	i;

	i = -1;
	while (++i < (max - min + 1))
		push_element(m, min, max);
}

void	solve(t_meta *m)
{
	int	chunks;
	int	max_idx;
	int	min_idx;
	int	rp;

	chunks = m->size / CHUNK_SIZE + 1;
	max_idx = cc_max(m->a);
	while (--chunks >= 0)
	{
		min_idx = ft_maxi(max_idx - CHUNK_SIZE, 0);
		push_chunk(m, min_idx, max_idx);
		sort_chunk(m);
		max_idx = min_idx - 1;
	}
	rp = cc_rpos(m->a, 0);
	if (rp < 0)
		com_n(C_RRA, -rp);
	else
		com_n(C_RA, rp);
}
