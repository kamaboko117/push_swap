/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:21:25 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/08 13:30:11 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

long	ft_atol(const char *str)
{
	unsigned long	i;
	long long int	ret;
	long long int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - 48);
		if (ret * sign > __LONG_LONG_MAX__)
			return (-1);
		if (ret * sign < -__LONG_LONG_MAX__)
			return (0);
		i++;
	}
	return (ret * sign);
}

void	exit_failure(char **args)
{
	free_split(args);
	exit(EXIT_FAILURE);
}

void	exit_free_a(int *a, char **args)
{
	free(a);
	exit_failure(args);
}

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

void	exit_search(t_data *data)
{
	free(data->a->stack);
	free(data->b->stack);
	exit(EXIT_FAILURE);
}
