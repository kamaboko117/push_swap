/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:38 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/29 14:47:46 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

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
	int	*index;
	int	i;
	int	j;

	index = init_index(data);
	if (index == NULL)
		exit(0);
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
