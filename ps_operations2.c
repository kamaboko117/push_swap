/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:15:12 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 18:22:59 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_data *data)
{
	rotate(data->a);
	return ("ra\n");
}

char	*rb(t_data *data)
{
	rotate(data->b);
	return ("rb\n");
}

char	*rr(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
	return ("rr\n");
}

char	*rra(t_data *data)
{
	reverse_rotate(data->a);
	return ("rra\n");
}

char	*rrb(t_data *data)
{
	reverse_rotate(data->b);
	return ("rrb\n");
}
