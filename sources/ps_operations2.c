/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:15:12 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:16:33 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ra(t_data *data)
{
	rotate(data->a);
	data->operations++;
	return ("ra\n");
}

char	*rb(t_data *data)
{
	rotate(data->b);
	data->operations++;
	return ("rb\n");
}

char	*rr(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
	data->operations++;
	return ("rr\n");
}

char	*rra(t_data *data)
{
	reverse_rotate(data->a);
	data->operations++;
	return ("rra\n");
}

char	*rrb(t_data *data)
{
	reverse_rotate(data->b);
	data->operations++;
	return ("rrb\n");
}
