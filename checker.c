/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:24 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 12:44:06 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
static void	ft_rest_operations(char *operation, \
		t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(operation, "pa\n", ft_strlen("pa\n")))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp(operation, "pb\n", ft_strlen("pb\n")))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp(operation, "ss\n", ft_strlen("ss\n")))
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	else
	{
		ft_clearstack(stack_a);
		ft_clearstack(stack_b);
		write(2, "Error\n", 6);
		exit(0);
	}
}

//
static void	ft_check_operations(char *operation, \
		t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(operation, "ra\n", ft_strlen("ra\n")))
		ft_rotate(stack_a);
	else if (!ft_strncmp(operation, "rb\n", ft_strlen("rb\n")))
		ft_rotate(stack_b);
	else if (!ft_strncmp(operation, "rr\n", ft_strlen("rr\n")))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (!ft_strncmp(operation, "sa\n", ft_strlen("sa\n")))
		ft_swap(*stack_a);
	else if (!ft_strncmp(operation, "sb\n", ft_strlen("sb\n")))
		ft_swap(*stack_b);
	else if (!ft_strncmp(operation, "rrr\n", ft_strlen("rrr\n")))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
	else if (!ft_strncmp(operation, "rrb\n", ft_strlen("rrb\n")))
		ft_rev_rotate(stack_b);
	else if (!ft_strncmp(operation, "rra\n", ft_strlen("rra\n")))
		ft_rev_rotate(stack_a);
	else
		ft_rest_operations(operation, stack_a, stack_b);
}

/*
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 1)
	{
		ft_check_arg(argv, &stack_a);
		str = get_next_line(0);
		while (str)
		{
			ft_check_operations(str, &stack_a, &stack_b);
			str = get_next_line(0);
		}
		if (ft_is_sorted(stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
*/