/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:19:58 by minsunki          #+#    #+#             */
/*   Updated: 2021/06/06 16:26:41 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		pstr(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int				main(int ac, char *av[])
{
	if (ac < 2)
	{
		pstr("Usage: ");
		pstr(av[0]);
		pstr(" int_list\n");
	}
	return (0);
}
