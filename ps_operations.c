/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:11:41 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 16:19:40 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	swap(data->a);
}

void	sb(t_data *data)
{
	swap(data->b);
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
}

void	pa(t_data *data)
{
	push(data->b, data->a);
}

void	pb(t_data *data)
{
	push(data->a, data->b);
}
