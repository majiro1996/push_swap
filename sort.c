/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:17:25 by manujime          #+#    #+#             */
/*   Updated: 2023/04/01 01:54:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main//sort//

#include "push_swap.h"

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_push_dx('b', stack_a, stack_b);
			pushed++;
		}
		else
			ft_rx('a', stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_push_dx('b', stack_a, stack_b);
		pushed++;
	}
}

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_rrx('a', stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rx('a', stack_a);
			lowest_pos--;
		}
	}
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_rest(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		shift_stack(stack_a);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		ft_sx('a', *stack_a);
	else if (stack_size == 3)
		ft_sort_three(stack_a);
	else if (stack_size > 3)
		ft_sort_rest(stack_a, stack_b);
}
