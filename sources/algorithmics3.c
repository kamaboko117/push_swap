/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:53:50 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/05 16:46:16 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	tmp_rotate_b(int tmp, t_data *data)
{
	while (tmp > 0)
	{
		ft_putstr_fd(rb(data), 1);
		tmp--;
	}
}

void	tmp_reverse_rotate_b(int tmp, t_data *data)
{
	while (tmp < data->b->size)
	{
		ft_putstr_fd(rrb(data), 1);
		tmp++;
	}
}

void	bring_lowest_to_top(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	if (data->b->size == 0)
		return ;
	i = -1;
	k = data->b->stack[0];
	while (++i < data->b->size)
	{
		if (k > data->b->stack[i])
		{
			k = data->b->stack[i];
			tmp = i;
		}
	}
	if (tmp <= data->b->size / 2)
		tmp_rotate_b(tmp, data);
	else
		tmp_reverse_rotate_b(tmp, data);
}

void	bring_highest_to_top(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	if (data->b->size == 0)
		return ;
	i = -1;
	k = data->b->stack[0];
	tmp = 0;
	while (++i < data->b->size)
	{
		if (k < data->b->stack[i])
		{
			k = data->b->stack[i];
			tmp = i;
		}
	}
	if (tmp <= data->b->size / 2)
		tmp_rotate_b(tmp, data);
	else
		tmp_reverse_rotate_b(tmp, data);
}
