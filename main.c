/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:40 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 20:45:29 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main //initialization//

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
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
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, parsed, is_parsed);
	stack_size = get_stack_size(stack_a);
	ft_set_index(stack_a, stack_size + 1);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
