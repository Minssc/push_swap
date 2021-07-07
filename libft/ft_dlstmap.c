/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:56:21 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 19:13:31 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*ret;
	t_dlist	*tmp;

	if (!f)
		return (0);
	ret = 0;
	while (lst)
	{
		tmp = ft_dlstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_dlstclear(&ret, del);
			return (0);
		}
		ft_dlstadd_back(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}
