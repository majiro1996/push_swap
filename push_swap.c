/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:33:26 by manujime          #+#    #+#             */
/*   Updated: 2023/03/20 16:57:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int	stack_size;
	
	if(argc < 2)
		return (0);
	if(ft_bad_input(argv))
		ft_exit_error(NULL, NULL);
	b = NULL;
	a = ft_fill_stack(argc, argv);
	stack_size = ft_get_size(a);
	ft_set_index(a, stack_size + 1);
	if(!ft_is_sorted(*a))
		ft_push_swap(&a, &b, stack_size);
	ft_free_stacks(&a, &b);
	return(0);
}
