/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/19 22:48:55 by asaboure         ###   ########.fr       */
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

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
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

void	display_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		ft_putnbr_fd(stack.stack[i], 1);
		i++;
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\n", 1);
}

void	realpush(int nb, t_stack stack)
{
	int	i;

	i = stack.size - 2;
	while (i >= 0)
	{
		stack.stack[i + 1] = stack.stack[i];
		i--;
	}
	stack.stack[0] = nb;
}

void	pop(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		stack.stack[i] = stack.stack[i + 1];
		i++;
	}
	stack.stack[i] = 0;
}

int	isempty(t_stack stack)
{
	if (stack.stack[0] == 0 && stack.stack[1] == 0)
		return (1);
	else
		return (0);
}
/*
void	pop_push(t_stack a)
{
	t_stack	b;
	int		tab[a.size];
	int		tmp;

	ft_bzero(tab, a.size);
	b.stack = tab;
	b.size = a.size;
	display_stack(a);
	display_stack(b);
	printf("\n");
	while (!isempty(a))
	{
		tmp = a.stack[0];
		pop(a);
		while (!isempty(b) && b.stack[0] < tmp)
		{
			realpush(b.stack[0], a);
			pop(b);
		}
		realpush(tmp, b);
	}
	display_stack(a);
	display_stack(b);
}*/

void	swap(t_stack stack)
{
	int	tmp;

	if (stack.size < 2)
		return ;
	tmp = stack.stack[1];
	stack.stack[1] = stack.stack[0];
	stack.stack[0] = tmp;
}

void	push(t_stack src, t_stack dst)
{
	realpush(src.stack[0], dst);
	pop(src);
}

void	rotate(t_stack stack)
{
	int	tmp;

	tmp = stack.stack[0];
	pop(stack);
	stack.stack[stack.size - 1] = tmp;
}

void	reverse_rotate(t_stack stack)
{
	realpush(stack.stack[stack.size - 1], stack);
}

void	push_swap(t_stack a)
{
	t_stack	b;
	int		*tab;
	int		tmp;

	tab = (int *)malloc(sizeof(int) * a.size);
	if (tab == NULL)
		exit(0);
	ft_bzero(tab, a.size * sizeof(int));
	b.stack = tab;
	b.size = a.size;
	display_stack(a);
	display_stack(b);
	(void)tmp;
	swap(a);
	display_stack(a);
	display_stack(b);
	push(a, b);
	display_stack(a);
	display_stack(b);
	rotate(a);
	display_stack(a);
	display_stack(b);
	reverse_rotate(a);
	display_stack(a);
	display_stack(b);
}

void	init_push_swap(int ac, char **av)
{
	t_stack	a;
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * ac);
	if (tab == NULL)
		exit(0);
	a.stack = tab;
	a.size = ac - 1;
	i = 1;
	while (i < ac)
	{
		a.stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	push_swap(a);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		usage();
	check_args(ac, av);
	init_push_swap(ac, av);
	return (1);
}
