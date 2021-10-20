/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 16:33:45 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
void	usage(void)
{
	write(1, "usage: ./push_swap [stack]\n", 28);
	exit(0);
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnum(av[i]))
		{
			ft_putstr_fd("Error\nStack should only contain ints\n", 1);
			exit(0);
		}
		i++;
	}
}

void	push_swap(t_data *data)
{
	int		tmp;

	display_stacks(data);
	(void)tmp;
	sa(data);
	display_stacks(data);
	pb(data);
	pb(data);
	pb(data);
	display_stacks(data);
	ra(data);
	display_stacks(data);
	rra(data);
	display_stacks(data);
	rb(data);
	display_stacks(data);
	rrb(data);
	display_stacks(data);
	rr(data);
	display_stacks(data);
}

void	init_push_swap(int ac, char **av)
{
	t_data	data;
	t_stack	b;
	t_stack	a;
	int		i;

	a.stack = (int *)malloc(sizeof(int) * ac);
	if (a.stack == NULL)
		exit(0);
	a.size = ac - 1;
	b.stack = (int *)malloc(sizeof(int) * ac);
	if (b.stack == NULL)
		exit(0);
	ft_bzero(b.stack, a.size * sizeof(int));
	b.size = 0;
	data.a = &a;
	data.b = &b;
	i = 1;
	while (i < ac)
	{
		a.stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	pop_push(&data);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		usage();
	check_args(ac, av);
	init_push_swap(ac, av);
	return (1);
}
