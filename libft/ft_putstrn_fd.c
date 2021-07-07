/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:25:59 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/02 01:57:43 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn_fd(char *s, int fd, size_t len)
{
	if (!s || fd < 0)
		return ;
	len = ft_mins(ft_strlen(s), len);
	write(fd, s, len);
}
