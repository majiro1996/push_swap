/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:09:36 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 21:15:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//position//

void	get_position(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*aux;
	int		lowest_index;
	int		lowest_pos;

	aux = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = aux->pos;
	while (aux)
	{
		if (aux->index < lowest_index)
		{
			lowest_index = aux->index;
			lowest_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (lowest_pos);
}

int	get_target(t_stack **a, int b_idx,
								int t_index, int target_pos)
{
	t_stack	*aux;

	aux = *a;
	while (aux)
	{
		if (aux->index > b_idx && aux->index < t_index)
		{
			t_index = aux->index;
			target_pos = aux->pos;
		}
		aux = aux->next;
	}
	if (t_index != INT_MAX)
		return (target_pos);
	aux = *a;
	while (aux)
	{
		if (aux->index < t_index)
		{
			t_index = aux->index;
			target_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;
	int		target_pos;

	aux_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (aux_b)
	{
		target_pos = get_target(a, aux_b->index, INT_MAX, target_pos);
		aux_b->target_pos = target_pos;
		aux_b = aux_b->next;
	}
}
