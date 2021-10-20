/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:11:41 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 18:20:23 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_data *data)
{
	swap(data->a);
	return ("sa\n");
}

char	*sb(t_data *data)
{
	swap(data->b);
	return ("sb\n");
}

char	*ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	return ("ss\n");
}

char	*pa(t_data *data)
{
	push(data->b, data->a);
	return ("pa\n");
}

char	*pb(t_data *data)
{
	push(data->a, data->b);
	return ("pb\n");
}
