/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:53 by manujime          #+#    #+#             */
/*   Updated: 2023/03/31 11:15:38 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//cost//

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = get_stack_size(aux_a);
	size_b = get_stack_size(aux_b);
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

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	aux = *stack_b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(aux->cost_b) + ft_abs(aux->cost_a);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
