/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:19:58 by minsunki          #+#    #+#             */
/*   Updated: 2021/06/06 18:17:45 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		perror_exit(char *estr)
{
	ft_putstr_fd("Error\n");
	ft_putstr_fd(estr, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

static void		parse(int *na, int n, char *av[])
{
	int			i;

	i = -1;
	while (++i < n)
	{
		if (!ft_isnumstr(av[i]))
			perror_exit("some arguments aren't integers");
		na[i] = ft_atoi(av[i]);
	}
}

int				main(int ac, char *av[])
{
	int			*na;

	if (ac < 2)
	{
		ft_putstr_fd("Usage: ", 1);
		ft_putstr_fd(av[0], 1);
		ft_putstr_fd(" int_list\n", 1);
		return (1); 
	}
	na = (int *)malloc(sizeof(int) * (ac - 1));
	parse(na, ac - 1, av + 1);
	for(int i=0; i<ac - 1; ++i){
		printf("%d ",na[i]);
	}
	printf("\n");
	
	free(na);
	return (0);
}
