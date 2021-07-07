/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:07:23 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/07 09:23:11 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	meta_destroy(void)
{
	t_meta			*m;

	m = get_meta();
	//ft_qclear(m->a, free);
	//ft_qclear(m->b, free);
	ft_dlstclear(&m->cl, free);
	if (m->ref)
		free(m->ref);
}

void	perror_exit(char *estr)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(estr, 1);
	ft_putstr_fd("\n", 1);
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
