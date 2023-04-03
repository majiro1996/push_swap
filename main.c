/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:40 by manujime          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
checks leaks at runtime, intended for debugging only
-add atexit(ft_leaks); at the start of the main function;
*/
/*
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
*/
/* fiill*/
void	ft_push_swap(char **argv, int is_parsed)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	stack_a = ft_fill_stack(argv, is_parsed);
	if (is_parsed == 0)
		ft_free_char_matrix(argv);
	stack_size = ft_get_stack_size(stack_a);
	ft_set_index(stack_a, stack_size + 1);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, stack_size);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

/*checks if there are enough arguments, if they need to be parsed and if 
there are errors in the input, then it calls the push_swap function*/
int	main(int argc, char **argv)
{
	char	**parsed;
	int		is_parsed;

	is_parsed = 1;
	parsed = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		parsed = ft_parse(argv);
		is_parsed = 0;
	}
	else
		parsed = argv;
	if (!ft_argv_check(parsed, is_parsed))
	{
		if (is_parsed == 0)
			ft_free_char_matrix(parsed);
		ft_printf("Error, nonvalid argument\n");
		return (0);
	}
	ft_push_swap(parsed, is_parsed);
	return (0);
}
