/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:54:58 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 19:11:00 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*t;

	if (!new || !lst)
		return ;
	t = ft_dlstlast(*lst);
	if (!t)
		*lst = new;
	else
	{
		t->next = new;
		new->prev = t;
	}
}
