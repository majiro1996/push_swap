/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:44:34 by manujime          #+#    #+#             */
/*   Updated: 2023/03/24 11:44:13 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap//

#include "push_swap.h"

void	ft_sx(char x, t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	if (x == 'a')
		ft_putstr("sa\n");
	if (x == 'b')
		ft_putstr("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sx(' ', *stack_a);
	ft_sx(' ', *stack_b);
	ft_putstr("ss\n");
}
