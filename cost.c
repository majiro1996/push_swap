/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:53 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 12:05:14 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*set the cost to move each element to the top of stack_b(cost_b)
and the cost get the target position at the top of stack_a(cost_a)
if the position of he node is lower than the median it's cost is set to be
negative to signal the need of reverse rotate instead of rotate*/
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = ft_get_stack_size(aux_a);
	size_b = ft_get_stack_size(aux_b);
	while (aux_b)
	{
		aux_b->cost_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > size_a / 2)
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

/*iterates through stack_b to get the cheapest node to move, and
and calls operation_ex to choose which operation to execute*/
void	ft_choose_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	aux = *stack_b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < cheapest)
		{
			cheapest = ft_abs(aux->cost_b) + ft_abs(aux->cost_a);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	ft_operation_ex(stack_a, stack_b, cost_a, cost_b);
}
