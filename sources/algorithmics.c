/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:38 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/08 13:30:03 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

/*The search rotates the A stack until it finds the Minimum. It pushes it into B
and then continues until A is sorted, at which point B should be reverse sorted,
it then pushes to A until B is empty. This should always sort A

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
*/

static void	sorted_insert(t_data *data)
{
	int	i;

	if (data->a->stack[0] < data->b->stack[data->b->size - 1] && data->a
		->stack[0] > data->b->stack[0])
	{
		ft_putstr_fd(pb(data), 1);
		return ;
	}
	i = 1;
	while (i < data->b->size)
	{
		if (data->a->stack[0] > data->b->stack[i] && data->a->stack[0] < data->b
			->stack[i - 1])
			break ;
		i++;
	}
	if (i <= data->b->size / 2)
		tmp_rotate_b(i, data);
	else
		tmp_reverse_rotate_b(i, data);
	ft_putstr_fd(pb(data), 1);
}

void	chunk_search(int *index, t_data *data, int ratio)
{
	int	first_hold;
	int	second_hold;

	first_hold = scan_first_hold(index, data, ratio);
	second_hold = scan_second_hold(index, data, ratio);
	if (first_hold <= data->a->size - second_hold)
		bring_first_top(data, first_hold);
	else
		bring_second_top(data, second_hold);
	if (is_stack_higher(data->a->stack[0], data->b)
		|| is_stack_lower(data->a->stack[0], data->b))
	{
		bring_highest_to_top(data);
		ft_putstr_fd(pb(data), 1);
	}
	else
		sorted_insert(data);
}

void	push_all_to_a(t_data *data)
{
	while (!isempty(data->b))
		ft_putstr_fd(pa(data), 1);
}

void	index_search(t_data *data, int ratio, int *index, int j)
{
	int	i;

	i = 0;
	while (i < (data->a->size + data->b->size) / ratio)
	{
		chunk_search(index + (((data->a->size + data->b->size) / ratio) * j),
			data, ratio);
		i++;
	}
}

void	the_search_but_better(t_data *data, int ratio)
{
	int	*index;
	int	j;

	index = init_index(data);
	if (index == NULL)
		exit_search(data);
	j = 0;
	while (j < ratio)
	{
		index_search(data, ratio, index, j);
		j++;
	}
	while (!isempty(data->a))
		index_search(data, ratio, index, j);
	bring_highest_to_top(data);
	push_all_to_a(data);
	free(index);
}
