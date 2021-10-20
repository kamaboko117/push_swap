/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:36:53 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/20 18:24:45 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*stack;
	int	size;
}				t_stack;

typedef struct s_data
{
	t_stack *a;
	t_stack	*b;
}				t_data;

int	isempty(t_stack *stack);
int	ft_isnum(char *str);
void	display_stacks(t_data *data);
void	pop_push(t_data *data);

void	realpush(int nb, t_stack *stack);
void	pop(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

char	*sa(t_data *data);
char	*sb(t_data *data);
char	*ss(t_data *data);

char	*pa(t_data *data);
char	*pb(t_data *data);

char	*ra(t_data *data);
char	*rb(t_data *data);
char	*rr(t_data *data);

char	*rra(t_data *data);
char	*rrb(t_data *data);
char	*rrr(t_data *data);
#endif