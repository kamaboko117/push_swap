/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:29:48 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 16:32:00 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	pop_push(t_data *data)
{
	int		tmp;

	data->b->size = data->a->size;
	display_stacks(data);
	ft_putstr_fd("\n", 1);
	while (!isempty(data->a))
	{
		tmp = data->a->stack[0];
		pop(data->a);
		while (!isempty(data->b) && data->b->stack[0] < tmp)
		{
			realpush(data->b->stack[0], data->a);
			pop(data->b);
		}
		realpush(tmp, data->b);
	}
	display_stacks(data);
}

void	realpush(int nb, t_stack *stack)
{
	int	i;

	i = stack->size - 2;
	while (i >= 0)
	{
		stack->stack[i + 1] = stack->stack[i];
		i--;
	}
	stack->stack[0] = nb;
}
