/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:44:34 by manujime          #+#    #+#             */
/*   Updated: 2023/03/29 23:31:10 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap//

#include "push_swap.h"

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

void	ft_ss(char mute, t_stack **stack_a, t_stack **stack_b)
{
	ft_sx(' ', *stack_a);
	ft_sx(' ', *stack_b);
	if (mute != ' ')
		ft_putstr("ss\n");
}
