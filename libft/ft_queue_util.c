/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:21:35 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 19:29:47 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qclear(t_que *q, void (*del)(void *))
{
	if (!q)
		return ;
	ft_dlstclear(&q->head, del);
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}
