/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:11:10 by asaboure          #+#    #+#             */
/*   Updated: 2021/11/03 14:13:19 by asaboure         ###   ########.fr       */
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
