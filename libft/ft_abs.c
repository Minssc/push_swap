/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:38:01 by minsunki          #+#    #+#             */
/*   Updated: 2021/07/01 18:37:19 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_absi(int v)
{
	if (v < 0)
		return (-v);
	return (v);
}

long long	ft_absl(long long v)
{
	if (v < 0)
		return (-v);
	return (v);
}

float	ft_absf(float v)
{
	if (v < 0)
		return (-v);
	return (v);
}

double	ft_absd(double v)
{
	if (v < 0)
		return (-v);
	return (v);
}
