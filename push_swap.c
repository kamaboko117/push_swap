/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/01 18:49:57 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
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

void	push_swap(t_data *data)
{
//	display_stacks(data);
	the_search_but_better(data, 5);
/*	display_stacks(data);
	if (is_sorted(data->a))
		printf("A is sorted. GG\n");
	else
		printf("epic fail\n");
	printf("operations: %d\n", data->operations);*/
}

void	init_push_swap(int count, char **args)
{
	t_data	data;
	t_stack	b;
	t_stack	a;
	int		i;

	a.stack = (int *)malloc(sizeof(int) * count);
	if (a.stack == NULL)
		exit(0);
	a.size = count;
	b.stack = (int *)malloc(sizeof(int) * count);
	if (b.stack == NULL)
		exit(0);
	ft_bzero(b.stack, a.size * sizeof(int));
	b.size = 0;
	data.a = &a;
	data.b = &b;
	data.operations = 0;
	i = 0;
	while (i < count)
	{
		a.stack[i] = ft_atoi(args[i]);
		i++;
	}
	push_swap(&data);
}

/*only free here if strjoin is used*/
void	init_args(int ac, char **av)
{
	char	*args;
	char	**split;
	int		i;

	args = av[1];
	i = 2;
	while (i < ac)
	{
		args = ft_strjoin(args, " ");
		args = ft_strjoin(args, av[i]);
		i++;
	}
	split = ft_split(args, ' ');
	i = 0;
	while (split[i])
		i++;
	init_push_swap(i, split);
}

/*will need to check that the numbers in the stack do not repeat.
check leaks on malloc errors*/
int	main(int ac, char **av)
{
	if (ac < 2)
		usage();
	check_args(ac, av);
	init_args(ac, av);
	return (1);
}
