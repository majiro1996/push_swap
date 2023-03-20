/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:42:29 by manujime          #+#    #+#             */
/*   Updated: 2023/03/20 15:37:31 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		sort_three_or_less(stack_a, stack_b);
	}
	else if (stack_a->size <= 5)
	{
		sort_five_or_less(stack_a, stack_b);
	}
	else
	{
		sort_larger_than_five(stack_a, stack_b);
	}
}
