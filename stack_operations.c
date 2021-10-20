/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:08:20 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 16:34:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = 0;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[1];
	stack->stack[1] = stack->stack[0];
	stack->stack[0] = tmp;
}

void	push(t_stack *src, t_stack *dst)
{
	if (src->size == 0)
		return ;
	dst->size++;
	realpush(src->stack[0], dst);
	pop(src);
	src->size--;
}

void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack[0];
	pop(stack);
	stack->stack[stack->size - 1] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	realpush(stack->stack[stack->size - 1], stack);
}
