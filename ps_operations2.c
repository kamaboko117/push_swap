/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:15:12 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 16:28:12 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	rotate(data->a);
}

void	rb(t_data *data)
{
	rotate(data->b);
}

void	rr(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
}

void	rra(t_data *data)
{
	reverse_rotate(data->a);
}

void	rrb(t_data *data)
{
	reverse_rotate(data->b);
}
