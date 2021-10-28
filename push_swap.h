/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:36:53 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/28 19:58:27 by asaboure         ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*b;
	int		operations;
}				t_data;

int		isempty(t_stack *stack);
int		ft_isnum(char *str);
void	display_stacks(t_data *data);
void	pop_push(t_data *data);
void	quicksort(int tab[], int first, int last);
int		is_sorted(t_stack *stack);
void	init_index(int *index, t_data *data);
void	the_search_but_better(t_data *data);
int		scan_first_hold(int *index, t_data *data);
int		scan_second_hold(int *index, t_data *data);
void	bring_first_top(t_data *data, int first_hold);
void	bring_second_top(t_data *data, int first_hold);
int		is_stack_higher(int x, t_stack *b);
int		is_stack_lower(int x, t_stack *b);
void	bring_highest_to_top(t_data *data);
void	bring_lowest_to_top(t_data *data);

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