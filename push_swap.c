/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:19:58 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 19:29:15 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	meta_init(t_meta *m, int size)
{
	m->a = (t_ccon *)ft_calloc(1, sizeof(t_ccon));
	if (!m->a)
		perror_exit("ft_calloc failed @meta_init for m->a");
	m->b = (t_ccon *)ft_calloc(1, sizeof(t_ccon));
	if (!m->b)
		perror_exit("ft_calloc failed @meta_init for m->b");
	m->ref = (int *)malloc(sizeof(int) * size);
	if (!m->ref)
		perror_exit("malloc failed @meta_init for m->ref");
	m->size = size;
}

int	main(int ac, char *av[])
{
	t_meta		*m;

	if (ac < 2)
		return (0);
	m = get_meta();
	meta_init(m, ac - 1);
	parse(m, ac - 1, av + 1);
	if (!cc_is_sorted(m->a))
	{
		if (ac - 1 > 5)
			solve(m);
		else
			solve_small(m);
	}
	meta_destroy();
	return (0);
}
