/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:40 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 13:39:45 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main //initialization//

#include "push_swap.h"

t_stack	*ft_fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
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
	t_stack	*node;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		node = stack;
		value = INT_MIN;
		highest = NULL;
		while (node)
		{
			if (node->value == INT_MIN && node->index == 0)
				node->index = 1;
			if (node->value > value && node->index == 0)
			{
				value = node->value;
				highest = node;
				node = stack;
			}
			else
				node = node->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!ft_argv_check(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	ft_set_index(stack_a, stack_size + 1);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
