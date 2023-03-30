/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:44:34 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 11:04:10 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*does nothing if there is less than two elements, swaps the value and index of 
the two first elements of the stack passed as argument, prints the action name 
based on a token char, if it's is not 'a' or 'b' it prints nothing*/
void	ft_sx(char x, t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return ;
	ft_swap(&stack->value, &stack->next->value);
	ft_swap(&stack->index, &stack->next->index);
	if (x == 'a')
		ft_putstr("sa\n");
	if (x == 'b')
		ft_putstr("sb\n");
}

/*execute swap in both stacks, prints the action name based on a token char, 
if its anything but ' ' it prints the action name*/
void	ft_ss(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_sx(' ', *stack_a);
	ft_sx(' ', *stack_b);
	if (mute != ' ')
		ft_putstr("ss\n");
}
