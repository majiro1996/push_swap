/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:24 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 23:56:55 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(op, "sa"))
		ft_sx('a', *stack_a);
	else if (!ft_strcmp(op, "sb"))
		ft_sx('b', *stack_b);
	else if (!ft_strcmp(op, "ss"))
		ft_ss('x', stack_a, stack_b);
	else if (!ft_strcmp(op, "ra"))
		ft_rx('a', stack_a);
	else if (!ft_strcmp(op, "rb"))
		ft_rx('b', stack_b);
	else if (!ft_strcmp(op, "rr"))
		ft_rr('x', stack_a, stack_b);
	else if (!ft_strcmp(op, "pa"))
		ft_push_dx('a', stack_b, stack_a);
	else if (!ft_strcmp(op, "pb"))
		ft_push_dx('b', stack_a, stack_b);
	else if (!ft_strcmp(op, "rra"))
		ft_rrx('a', stack_a);
	else if (!ft_strcmp(op, "rrb"))
		ft_rrx(!'b', stack_b);
	else if (ft_strcmp(op, "rrr"))
		ft_rrr(!'x', stack_a, stack_b);
	else
		exit_error(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;

	if (argc < 2)
		return (0);
	if (!ft_argv_check(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, argv);
	op = get_next_line(0);
	while (op)
	{
		ft_printf("line: %s", op);
		ft_do_op(op, &stack_a, &stack_b);
		op = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
