/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:09:36 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 12:52:26 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sets the position variable of each node to it's current 
position in the stack*/
void	ft_set_position(t_stack **stack)
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

/*iterates through the stack, finds the node with the lowest index 
and returns it's position*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*aux;
	int		lowest_index;
	int		lowest_pos;

	aux = *stack;
	lowest_index = INT_MAX;
	ft_set_position(stack);
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

/*returns the target position in stack a for a given node of stack b*/
int	ft_get_target(t_stack **a, int b_idx, int t_index, int target_pos)
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

/*sets the target position for each node of stack b*/
void	ft_set_target_position(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;
	int		target_pos;

	aux_b = *b;
	ft_set_position(a);
	ft_set_position(b);
	target_pos = 0;
	while (aux_b)
	{
		target_pos = ft_get_target(a, aux_b->index, INT_MAX, target_pos);
		aux_b->target_pos = target_pos;
		aux_b = aux_b->next;
	}
}
