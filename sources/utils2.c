/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:26 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/29 14:48:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static void	qs_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int tab[], int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (tab[i] <= tab[pivot] && i < last)
				i++;
			while (tab[j] > tab[pivot])
				j--;
			if (i < j)
			{
				qs_swap(&tab[i], &tab[j]);
			}
		}
		qs_swap(&tab[pivot], &tab[j]);
		quicksort(tab, first, j - 1);
		quicksort(tab, j + 1, last);
	}
}

int	*init_index(t_data *data)
{
	int	i;
	int	*index;

	index = (int *)malloc(sizeof(int) * data->a->size);
	if (index == NULL)
		return (NULL);
	i = 0;
	while (i < data->a->size)
	{
		index[i] = data->a->stack[i];
		i++;
	}
	quicksort(index, 0, data->a->size - 1);
	return (index);
}

int	is_stack_higher(int x, t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (x < b->stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_lower(int x, t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (x > b->stack[i])
			return (0);
		i++;
	}
	return (1);
}
