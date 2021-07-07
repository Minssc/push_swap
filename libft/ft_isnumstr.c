/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:12:46 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 19:16:57 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumstr(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
