/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:24 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 20:47:26 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_op(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(op, "sa"))
		ft_sx(' ', stack_a);
	if (!ft_strcmp(op, "sb"))
		ft_sx(' ', stack_b);
	if (!ft_strcmp(op, "ra"))
		ft_rx(' ', stack_a);
	if (!ft_strcmp(op, "rb"))
		ft_rx(' ', stack_b);
	if (!ft_strcmp(op, "rr"))
		ft_rr(' ', stack_a, stack_b);
	if (!ft_strcmp(op, "pa"))
		ft_push_dx(' ', stack_b, stack_a);
	if (!ft_strcmp(op, "pb"))
		ft_push_dx(' ', stack_a, stack_b);
	if (!ft_strcmp(op, "rra"))
		
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
