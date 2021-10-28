/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:38 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 20:05:28 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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
	i = -1;
	if (k < data->a->size / 2)
	{
		while (++i < k)
			ft_putstr_fd(ra(data), 1);
	}
	else
	{
		k = data->a->size - k;
		while (++i < k)
			ft_putstr_fd(rra(data), 1);
	}
	if (!is_sorted(data->a))
	{	
		ft_putstr_fd(pb(data), 1);
		the_search(data);
	}
	while (!isempty(data->b))
		ft_putstr_fd(pa(data), 1);
}

void	sorted_insert(t_data *data)
{
	while (data->a->stack[0] < data->b->stack[data->b->size - 1])
		ft_putstr_fd(rrb(data), 1);
	while (data->a->stack[0] > data->b->stack[0])
		ft_putstr_fd(rb(data), 1);
	ft_putstr_fd(pb(data), 1);
}

void	chunk_search(int *index, t_data *data)
{
	int	first_hold;
	int	second_hold;

	first_hold = scan_first_hold(index, data);
	second_hold = scan_second_hold(index, data);
	if (first_hold <= data->a->size - second_hold)
		bring_first_top(data, first_hold);
	else
		bring_second_top(data, second_hold);
	if (is_stack_higher(data->a->stack[0], data->b)
		|| is_stack_lower(data->a->stack[0], data->b))
	{
		bring_lowest_to_top(data);
		ft_putstr_fd(pb(data), 1);
	}
	else
		sorted_insert(data);
}

void	the_search_but_better(t_data *data)
{
	int	index[data->a->size];
	int	i;
	int	j;

	init_index(index, data);
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < (data->a->size + data->b->size) / 5)
		{
			chunk_search(index + (((data->a->size + data->b->size) / 5) * j),
						data);
			i++;
		}
		j++;
	}
	bring_highest_to_top(data);
}
