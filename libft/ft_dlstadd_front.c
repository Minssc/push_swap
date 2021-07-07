/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:55:13 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 19:11:09 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist		*t;

	if (!new || !lst)
		return ;
	t = ft_dlstfirst(*lst);
	if (!t)
		*lst = new;
	else
	{
		t->prev = new;
		new->next = *lst;
	}
}
