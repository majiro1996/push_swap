/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:44:26 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 00:20:47 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate//push//reverse_rotate//

void	ft_rx(char x, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
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
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	if (dx == 'a')
		ft_putstr("pa\n");
	if (dx == 'b')
		ft_putstr("pb\n");
}

void	ft_rrx(char x, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
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
