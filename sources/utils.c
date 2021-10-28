/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:23:25 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:16:55 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	isempty(t_stack *stack)
{
	if (stack->stack[0] == 0 && stack->stack[1] == 0)
		return (1);
	else
		return (0);
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

void	display_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd(stack->stack[i], 1);
		i++;
		if (i != stack->size)
			ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\n", 1);
}

void	display_stacks(t_data *data)
{
	display_stack(data->a);
	display_stack(data->b);
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
