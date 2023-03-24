/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:43 by manujime          #+#    #+#             */
/*   Updated: 2023/03/24 11:59:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sort_tiny//
int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	ft_sort_three(t_stack **stack)
{
	int		highest;

	if (ft_is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ft_rx('a', stack);
	else if ((*stack)->next->index == highest)
		ft_rrx('a', stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sx('a', *stack);
}
