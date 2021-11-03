/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:03:42 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/03 14:14:49 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static void	tmp_rotate_a(int tmp, t_data *data)
{
	while (tmp > 0)
	{
		ft_putstr_fd(ra(data), 1);
		tmp--;
	}
}

static void	tmp_reverse_rotate_a(int tmp, t_data *data)
{
	while (tmp < data->a->size)
	{
		ft_putstr_fd(rra(data), 1);
		tmp++;
	}
}

void	bring_lowest_to_top_a(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	if (data->a->size == 0)
		return ;
	i = -1;
	k = data->a->stack[0];
	while (++i < data->a->size)
	{
		if (k > data->a->stack[i])
		{
			k = data->a->stack[i];
			tmp = i;
		}
	}
	if (tmp <= data->a->size / 2)
		tmp_rotate_a(tmp, data);
	else
		tmp_reverse_rotate_a(tmp, data);
}

void	sorted_insert_to_a(t_data *data)
{
	while (data->b->stack[0] > data->a->stack[0])
		ft_putstr_fd(ra(data), 1);
	while (data->b->stack[0] < data->a->stack[data->a->size - 1])
		ft_putstr_fd(rra(data), 1);
	ft_putstr_fd(pa(data), 1);
}

void	sort_five_stack(t_data *data)
{
	while (data->a->size > 3)
		ft_putstr_fd(pb(data), 1);
	sort_three_stack(data);
	while (!isempty(data->b))
	{
		if (is_stack_higher(data->b->stack[0], data->a)
			|| is_stack_lower(data->b->stack[0], data->a))
		{
			bring_lowest_to_top_a(data);
			ft_putstr_fd(pa(data), 1);
		}
		else
			sorted_insert_to_a(data);
	}
	bring_lowest_to_top_a(data);
}
