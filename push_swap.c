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
	if (argv < 2)
	{
	//	ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	t_stack *a;
	t_stack *b;

	if (!initilalize_stacks(&a, &b, argc, argv))
	{
	//	ft_putstr_fd("Error\n", STDERR_FILENO);
		return(1);
	}
	if (!is_sorted(a))
		sort(a, b);
	free_stacks(a, b);
	return(0);
}
