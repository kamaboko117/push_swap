/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:11:10 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/08 13:45:41 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	init_push_swap(int count, char **args)
{
	t_data	data;
	t_stack	b;
	t_stack	a;
	int		i;

	a.stack = (int *)malloc(sizeof(int) * count);
	if (a.stack == NULL)
		exit_failure(args);
	a.size = count;
	b.stack = (int *)malloc(sizeof(int) * count);
	if (b.stack == NULL)
		exit_free_a(a.stack, args);
	ft_bzero(b.stack, a.size * sizeof(int));
	b.size = 0;
	data.a = &a;
	data.b = &b;
	data.operations = 0;
	i = -1;
	while (++i < count)
		a.stack[i] = ft_atoi(args[i]);
	free_split(args);
	push_swap(&data);
	free(a.stack);
	free(b.stack);
}

void	check_repeat(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]) && i != j)
			{
				ft_putstr_fd("Error\nStack should not contain repetitions\n",
					1);
				free_split(args);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_overflow(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_atol(args[i]) > 2147483647L || ft_atol(args[i]) < -2147483647
			|| ft_strlen(args[i]) > 12)
		{
			ft_putstr_fd("Error\n", 1);
			free_split(args);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	init_args(int ac, char **av)
{
	char	*args;
	char	**split;
	int		i;

	args = ft_strdup(av[1]);
	i = 2;
	while (i < ac)
	{
		ft_strjoin_free(&args, " ");
		ft_strjoin_free(&args, av[i]);
		i++;
	}
	split = ft_split(args, ' ');
	free(args);
	check_overflow(split);
	check_repeat(split);
	i = 0;
	while (split[i])
		i++;
	init_push_swap(i, split);
}
