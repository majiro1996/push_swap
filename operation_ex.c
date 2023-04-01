/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:14:00 by manujime          #+#    #+#             */
/*   Updated: 2023/04/01 02:28:39 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotates both stacks based on cost*/
void	ft_rotate_both_ex(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr('x', a, b);
	}
}

/*reverse rotates both stacks based on cost*/
void	ft_rev_rotate_both_ex(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr('x', a, b);
	}
}

/*does rotate or reverse rotate to the stack based on cost*/
void	ft_rotate_ex(char name, t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rx(name, stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrx(name, stack);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rev_rotate_both_ex(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both_ex(a, b, &cost_a, &cost_b);
	ft_rotate_ex('a', a, &cost_a);
	ft_rotate_ex('b', b, &cost_b);
	ft_push_dx('a', b, a);
}
