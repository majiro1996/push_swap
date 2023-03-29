/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:24 by manujime          #+#    #+#             */
/*   Updated: 2023/03/29 17:50:14 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		ft_sx(' ', *stack_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		ft_sx(' ', *stack_b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ft_ss(' ', stack_a, stack_b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ft_rx(' ', stack_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		ft_rx(' ', stack_b);
	else if (ft_strcmp(op, "rr\n") == 0)
		ft_rr(' ', stack_a, stack_b);
	else if (ft_strcmp(op, "pa\n") == 0)
		ft_push_dx(' ', stack_b, stack_a);
	else if (ft_strcmp(op, "pb\n") == 0)
		ft_push_dx(' ', stack_a, stack_b);
	else if (ft_strcmp(op, "rra\n") == 0)
		ft_rrx(' ', stack_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		ft_rrx(' ', stack_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		ft_rrr(' ', stack_a, stack_b);
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
		free(op);
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
