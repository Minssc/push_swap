/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:19:58 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/07 09:18:41 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse(t_ccon *c, int *ref, int n, char *av[])
{
	int			i;
	int			j;
	long long	tl;

	i = -1;
	while (++i < n)
	{
		if (!ft_isnumstr(av[i]))
			perror_exit("some arguments aren't integers");
		tl = ft_atoi(av[i]);
		if (tl < INT_MIN || INT_MAX < tl)
			perror_exit("integer value out of range");
		cc_push(c, (int)tl);
		ref[i] = (int)tl;
		j = i;
		while (--j >= 0)
			if (ref[j] == ref[i])
				perror_exit("duplicate value");
	}
}

static void	print_usage(char *pname)
{
	ft_putstr_fd("Usage: ", 1);
	ft_putstr_fd(pname, 1);
	ft_putstr_fd(" int_list\n", 1);
	exit(0);
}

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

static void	sort(int *arr, int size)
{
	int			i;
	int			j;
	int			si;
	int			t;

	i = -1;
	while (++i < size)
	{
		si = i;
		j = i;
		while (++j < size)
			if (arr[j] < arr[si])
				si = j;
		t = arr[i];
		arr[i] = arr[si];
		arr[si] = t;
	}
}

int	main(int ac, char *av[])
{
	t_meta		*m;

	if (ac < 2)
		print_usage(av[0]);
	meta_init((m = get_meta()), ac - 1);
	parse(m->a, m->ref, ac - 1, av + 1);
	sort(m->ref, ac - 1);
	solve(m);
	return (0);
}
