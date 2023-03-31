/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:05:18 by manujime          #+#    #+#             */
/*   Updated: 2023/03/31 16:04:23 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*frees each node of the stack and sets the stack pointer to NULL*/
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack && *stack)
	{
		return ;
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
	*stack = NULL;
}

/*exits the program with an error message and frees the memory allocated 
to both stacks*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/*creates a linked list stack_a by converting valid integer strings in 
the argv array to integer nodes.*/
t_stack	*ft_fill_stack(char **argv, int parsed)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;
	int			len;

	len = ft_count_strings(argv);
	stack_a = NULL;
	nb = 0;
	i = parsed;
	while (i < len)
	{
		nb = ft_atoi(argv[i]);
		if (i != parsed)
			ft_add_stack_end(&stack_a, ft_new_node((int)nb));
		else
			stack_a = ft_new_node((int)nb);
		i++;
	}
	return (stack_a);
}

/*assigns an index value to each node, starting from the highest value 
node with the index "size" and ending with the lowest value node with 
the index "1".*/
void	ft_set_index(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*highest;
	int		i;

	i = size;
	while (i > 0)
	{
		current = stack;
		highest = NULL;
		while (current)
		{
			if (current->value != INT_MIN && current->index == 0)
			{
				if (!highest || current->value > highest->value)
					highest = current;
			}
			current = current->next;
		}
		if (highest)
			highest->index = i;
		i--;
	}
}

/*prints the contets of the stack, intended for debugging only*/
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
