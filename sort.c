/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:17:25 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 10:51:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main//sort//

#include "push_swap.h"

/*does pb to all values but three in stack_a, it sends the values with a
lower index than the median are pushed first*/
void	ft_push_all_but_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (pushed < stack_size / 2 && (stack_size / 2) > 3 && i < stack_size)
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

/**/
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

/*iterates through the stack checking if no value has a higher 
next than it's own*/
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

/*leaves three nodes in stack_a and sorts them, executes the most efective 
operations and shift the stack until a is sorted*/
void	ft_sort_rest(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_all_but_three(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_set_target_position(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);
		ft_choose_cheapest(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		shift_stack(stack_a);
}

/*chooses one of the sorting functions for each case*/
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		ft_sx('a', *stack_a);
	else if (stack_size == 3)
		ft_sort_three(stack_a);
	else if (stack_size > 3)
		ft_sort_rest(stack_a, stack_b);
}
