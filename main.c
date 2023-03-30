/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:40 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 21:36:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main //initialization//

#include "push_swap.h"

/*
void	print_strings(char** arr) 
{
    for (int i = 0; arr[i] != NULL; i++) 
	{
        printf("**%s\n", arr[i]);
    }
}
*/

void	ft_push_swap(char **argv, int is_parsed)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	stack_a = ft_fill_stack(argv, is_parsed);
	stack_size = get_stack_size(stack_a);
	ft_set_index(stack_a, stack_size + 1);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

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
		exit_error(NULL, NULL);
	ft_push_swap(parsed, is_parsed);
	return (0);
}
