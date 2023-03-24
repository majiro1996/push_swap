/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:20:41 by manujime          #+#    #+#             */
/*   Updated: 2023/03/23 15:33:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack_values(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf(" %d |", current->value);
		current = current->next;
	}
	printf("\n");
}
