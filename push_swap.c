/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/08 14:05:45 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	usage(void)
{
	write(1, "usage: ./push_swap [stack]\n", 28);
	exit(0);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '\0')
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
				{
					ft_putstr_fd("Error\nStack should only contain ints\n", 1);
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}

void	sort_two_stack(t_data *data)
{
	if (!is_sorted(data->a))
		ft_putstr_fd(sa(data), 1);
}

void	push_swap(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (data->a->size == 2)
		sort_two_stack(data);
	if (data->a->size == 3)
		sort_three_stack(data);
	if (data->a->size > 3 && data->a->size <= 5)
		sort_five_stack(data);
	if (data->a->size > 5 && data->a->size < 500)
		the_search_but_better(data, 5);
	if (data->a->size >= 500)
		the_search_but_better(data, 11);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	check_args(ac, av);
	init_args(ac, av);
	return (1);
}
