/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:14:43 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 19:33:31 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_int(char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != ' ')
			return (0);
		s++;
	}
	return (1);
}

static void	ref_sort(int *arr, int size)
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

static void	list_to_index(t_meta *m)
{
	int		idx;
	t_dlist	*cur;

	cur = m->a->head;
	while (cur)
	{
		idx = 0;
		while (m->ref[idx] != *(int *)cur->content)
			idx++;
		*(int *)cur->content = idx;
		cur = cur->next;
	}
}

void	parse(t_meta *m, int ac, char *av[])
{
	int			i;
	int			j;
	long long	tl;

	i = ac;
	while (--i >= 0)
	{
		if (!validate_int(av[i]))
			perror_exit("Invalid integer");
		tl = ft_atol(av[i]);
		if (tl < INT_MIN || INT_MAX < tl)
			perror_exit("Integer out of range");
		cc_push(m->a, (int)tl);
		m->ref[i] = (int)tl;
		j = i;
		while (++j < ac)
			if (m->ref[j] == m->ref[i])
				perror_exit("duplicate value");
	}
	ref_sort(m->ref, ac);
	list_to_index(m);
}
