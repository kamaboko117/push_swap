/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/26 13:09:38 by asaboure         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*The wheel will occasionally work... often it will just spin indefinitely: do
not use this*/
void	the_wheel(t_data *data)
{
	display_stacks(data);
	while (!is_sorted(data->a))
	{
		if (data->a->stack[0] < data->a->stack[1])
			ft_putstr_fd(ra(data), 1);
		else
		{
			ft_putstr_fd(ra(data), 1);
			if (!is_sorted(data->a))
				ft_putstr_fd(pb(data), 1);
		}
	}
	display_stacks(data);
	while (!isempty(data->b))
	{
		if (data->b->stack[0] < data->a->stack[0])
			ft_putstr_fd(pa(data), 1);
		else
			ft_putstr_fd(ra(data), 1);
	}
	while (!is_sorted(data->a))
		ft_putstr_fd(rra(data), 1);
	display_stacks(data);
}

/*The search rotates the A stack until it finds the Minimum. It pushes it into B
and then continues until A is sorted, at which point B should be reverse sorted,
it then pushes to A until B is empty. This should always sort A*/
void	the_search(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	k = 0;
	tmp = data->a->stack[0];
	while (i < data->a->size)
	{
		if (tmp > data->a->stack[i])
		{
			k = i;
			tmp = data->a->stack[i];
		}
		i++;
	}
	ft_putnbr_fd(k, 1);
	i = -1;
	while (++i < k)
		ft_putstr_fd(ra(data), 1);
	if (!is_sorted(data->a))
	{	
		ft_putstr_fd(pb(data), 1);
		the_search(data);
	}
	while (!isempty(data->b))
		ft_putstr_fd(pa(data), 1);
}

/*void	the_search_but_better(t_data *data)
{
	
}*/

void	push_swap(t_data *data)
{
	display_stacks(data);
	the_search(data);
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
	data.operations = 0;
	i = 1;
	while (i < ac)
	{
		a.stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	push_swap(&data);
}

/*will need to check that the numbers in the stack do not repeat*/
int	main(int ac, char **av)
{
	if (ac < 2)
		usage();
	check_args(ac, av);
	init_push_swap(ac, av);
	return (1);
}
