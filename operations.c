/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:44:26 by manujime          #+#    #+#             */
/*   Updated: 2023/04/01 02:19:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*does nothing if there is less than two nodes, swaps the value and index of 
the two first nodes of the stack passed as argument, prints the action name 
based on a token char, if it's is not 'a' or 'b' it prints nothing*/
void	ft_rx(char x, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	aux = *stack;
	*stack = (*stack)->next;
	last = ft_get_last(*stack);
	aux->next = NULL;
	last->next = aux;
	if (x == 'a')
		ft_putstr("ra\n");
	if (x == 'b')
		ft_putstr("rb\n");
}

void	ft_rr(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_rx(' ', stack_a);
	ft_rx(' ', stack_b);
	if (mute != ' ')
		ft_putstr("rr\n");
}

void	ft_push_dx(char dx, t_stack **src, t_stack **dest)
{
	t_stack	*aux;

	if (*src == NULL)
		return ;
	aux = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = aux;
	if (dx == 'a')
		ft_putstr("pa\n");
	if (dx == 'b')
		ft_putstr("pb\n");
}

void	ft_rrx(char x, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;
	t_stack	*before_last;

	last = ft_get_last(*stack);
	before_last = ft_get_second_last(*stack);
	aux = *stack;
	*stack = last;
	(*stack)->next = aux;
	before_last->next = NULL;
	if (x == 'a')
		ft_putstr("rra\n");
	if (x == 'b')
		ft_putstr("rrb\n");
}

void	ft_rrr(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_rrx(' ', stack_a);
	ft_rrx(' ', stack_b);
	if (mute != ' ')
		ft_putstr("rrr\n");
}
