/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:27:39 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:17:05 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*rrr(t_data *data)
{
	reverse_rotate(data->b);
	reverse_rotate(data->a);
	data->operations++;
	return ("rrr\n");
}
