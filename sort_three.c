/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:43 by manujime          #+#    #+#             */
/*   Updated: 2023/04/03 16:35:38 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*iterates through the stack to get the highest index of a node*/
int	ft_get_highest_index(t_stack *stack)
{
	int		highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

/*executes ra or rra if the highest is the first or the second respectively,
then checks if the first two numbers need to be swaped*/
void	ft_sort_three(t_stack **stack)
{
	int		highest;

	highest = ft_get_highest_index(*stack);
	if ((*stack)->index == highest)
		ft_rx('a', stack);
	else if ((*stack)->next->index == highest)
		ft_rrx('a', stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sx('a', *stack);
}
