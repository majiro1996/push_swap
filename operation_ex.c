/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:14:00 by manujime          #+#    #+#             */
/*   Updated: 2023/04/03 16:37:35 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotates both stacks based on cost*/
void	ft_rr_ex(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr('x', a, b);
	}
}

/*reverse rotates both stacks based on cost*/
void	ft_rrr_ex(t_stack **a, t_stack **b,
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
void	ft_rx_or_rrx_ex(char name, t_stack **stack, int *cost)
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

/*chooses wich operation to execute based on cost*/
void	ft_operation_ex(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rrr_ex(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rr_ex(a, b, &cost_a, &cost_b);
	ft_rx_or_rrx_ex('a', a, &cost_a);
	ft_rx_or_rrx_ex('b', b, &cost_b);
	ft_push_dx('a', b, a);
}
