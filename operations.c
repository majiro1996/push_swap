/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:44:26 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 12:59:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotates the first node of the stack to the last position, 
prints the action name based on a token char*/
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

/*rotates both stacks, prints the action name based on a token char*/
void	ft_rr(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_rx(' ', stack_a);
	ft_rx(' ', stack_b);
	if (mute != ' ')
		ft_putstr("rr\n");
}

/*push the first node of dest to src, prints the action name 
based on a token char*/
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

/*rotates the last node of the stack to the first position, 
prints the action name based on a token char*/
void	ft_rrx(char x, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;
	t_stack	*second_last;

	last = ft_get_last(*stack);
	second_last = ft_get_second_last(*stack);
	second_last->next = NULL;
	aux = *stack;
	*stack = last;
	(*stack)->next = aux;
	if (x == 'a')
		ft_putstr("rra\n");
	if (x == 'b')
		ft_putstr("rrb\n");
}

/*reverse rotates both stacks, prints the action name based on a token char*/
void	ft_rrr(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_rrx(' ', stack_a);
	ft_rrx(' ', stack_b);
	if (mute != ' ')
		ft_putstr("rrr\n");
}
