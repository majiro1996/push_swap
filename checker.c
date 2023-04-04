/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:24 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 14:08:20 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_leaks(void)
{
	system("leaks -q checker");
}
*/
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Error\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(1);
}

/*checks if the imput string is an operation name, if it find a matching 
name it's executed, if there's no match both stacks are freed, prints,
"Error" and exit the program*/
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
		ft_exit_error(stack_a, stack_b);
}

/*fills stack, gets the input and executes the operations, 
if the stack is sorted it prints "OK, if it's not it prints "KO"*/
int	ft_checker(char **argv, int is_parsed)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;

	stack_b = NULL;
	stack_a = ft_fill_stack(argv, is_parsed);
	op = get_next_line(0);
	while (op)
	{
		ft_do_op(op, &stack_a, &stack_b);
		free(op);
		op = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

/*checks if there are enough arguments, if they need to be parsed and if 
there are errors in the input, then it calls the checker function*/
int	main(int argc, char **argv)
{
	char	**parsed;
	int		is_parsed;

	is_parsed = 1;
	parsed = NULL;
	if (argc == 2)
	{
		parsed = ft_parse(argv);
		is_parsed = 0;
	}
	else
		parsed = argv;
	if (argc < 2)
		return (0);
	if (!ft_argv_check(parsed, is_parsed))
	{
		ft_printf("Error, nonvalid argument\n");
		return (0);
	}
	ft_checker(parsed, is_parsed);
	return (0);
}
