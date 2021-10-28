/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmics2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:46:46 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:56:25 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	scan_first_hold(int *index, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->a->size)
	{
		j = 0;
		while (j < (data->a->size + data->b->size) / 5)
		{
			if (data->a->stack[i] == index[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	scan_second_hold(int *index, t_data *data)
{
	int	i;
	int	j;

	i = data->a->size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < (data->a->size + data->b->size) / 5)
		{
			if (data->a->stack[i] == index[j])
				return (i);
			j++;
		}
		i--;
	}
	return (0);
}

void	bring_first_top(t_data *data, int first_hold)
{
	int	i;

	i = 0;
	while (i < first_hold)
	{
		ft_putstr_fd(ra(data), 1);
		i++;
	}
}

void	bring_second_top(t_data *data, int second_hold)
{
	int	i;

	i = 0;
	while (i < data->a->size - second_hold)
	{
		ft_putstr_fd(rra(data), 1);
		i++;
	}
}
