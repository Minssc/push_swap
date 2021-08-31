/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:07:23 by minsunki          #+#    #+#             */
/*   Updated: 2021/08/31 16:15:52 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	meta_destroy(void)
{
	t_meta			*m;

	m = get_meta();
	ft_dlstclear(m->a, free);
	ft_dlstclear(m->b, free);
	if (m->ref)
		free(m->ref);
	if (m->a)
		free(m->a);
	if (m->b)
		free(m->b);
}

void	perror_exit(char *estr)
{
	ft_putstr_fd("Error\n", 2);
	if (FT_DBG)
	{
		ft_putstr_fd(estr, 2);
		ft_putstr_fd("\n", 2);
	}
	meta_destroy();
	exit(1);
}

t_meta	*get_meta(void)
{
	static t_meta	*m;

	if (!m)
		m = (t_meta *)ft_calloc(1, sizeof(t_meta));
	if (!m)
		perror_exit("ft_calloc failed @get_meta for meta initialization");
	return (m);
}
