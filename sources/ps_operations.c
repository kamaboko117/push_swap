/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:11:41 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:16:19 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*sa(t_data *data)
{
	swap(data->a);
	data->operations++;
	return ("sa\n");
}

char	*sb(t_data *data)
{
	swap(data->b);
	data->operations++;
	return ("sb\n");
}

char	*ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	data->operations++;
	return ("ss\n");
}

char	*pa(t_data *data)
{
	push(data->b, data->a);
	data->operations++;
	return ("pa\n");
}

char	*pb(t_data *data)
{
	push(data->a, data->b);
	data->operations++;
	return ("pb\n");
}
