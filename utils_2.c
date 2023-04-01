/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:54:13 by manujime          #+#    #+#             */
/*   Updated: 2023/04/01 01:50:32 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//allocates a new node for the stack//
t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/**/
int	ft_get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (stack)
	{
		while (stack)
		{
			stack = stack->next;
			size++;
		}
		return (size);
	}
	return (0);
}

/*iterates through the stack until it finds the last node and returns it*/
t_stack	*ft_get_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*iterates through the stack until it finds the second last node 
and returns it*/
t_stack	*ft_get_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*adds node to the end of the stack, if there is no nodes in the stack
 it adds the first node*/
void	ft_add_stack_end(t_stack **stack, t_stack *new)
{
	t_stack	*end;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	end = ft_get_last(*stack);
	end->next = new;
}
