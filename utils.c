/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:05:18 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 20:33:42 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//utils//

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

t_stack	*ft_fill_stack(int argc, char **argv, int parsed)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = parsed;
	ft_printf("%i\n", argc);
	ft_printf("%i\n", ft_count_strings(argv));
	while (i < ft_count_strings(argv))
	{
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	ft_set_index(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		current = stack;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			if (current->value == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->value > value && current->index == 0)
			{
				value = current->value;
				highest = current;
				current = stack;
			}
			else
				current = current->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

void	ft_print_stack_values(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf(" %d |", current->value);
		current = current->next;
	}
	ft_printf("\n");
}
