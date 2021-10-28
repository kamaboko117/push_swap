/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:53:50 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:56:52 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	bring_lowest_to_top(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	if (data->b->size == 0)
		return ;
	i = 0;
	k = data->b->stack[0];
	while (i < data->b->size)
	{
		if (k > data->b->stack[i])
		{
			k = data->b->stack[i];
			tmp = i;
		}
		i++;
	}
	if (tmp <= data->b->size / 2)
	{
		while (tmp > 0)
		{
			ft_putstr_fd(rb(data), 1);
			tmp--;
		}
	}
	else
	{
		while (tmp < data->b->size)
		{
			ft_putstr_fd(rrb(data), 1);
			tmp++;
		}
	}
}

void	bring_highest_to_top(t_data *data)
{
	int	i;
	int	k;
	int	tmp;

	if (data->b->size == 0)
		return ;
	i = 0;
	k = data->b->stack[0];
	while (i < data->b->size)
	{
		if (k < data->b->stack[i])
		{
			k = data->b->stack[i];
			tmp = i;
		}
		i++;
	}
	if (tmp <= data->b->size / 2)
	{
		while (tmp > 0)
		{
			ft_putstr_fd(rb(data), 1);
			tmp--;
		}
	}
	else
	{
		while (tmp < data->b->size)
		{
			ft_putstr_fd(rrb(data), 1);
			tmp++;
		}
	}
}
