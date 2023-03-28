/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:14:00 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 19:01:51 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do_move//

void	do_rev_rotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr('x', a, b);
	}
}

void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr('x', a, b);
	}
}

void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rx('a', a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrx('a', a);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rx('b', b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrx('b', b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	ft_push_dx('a', b, a);
}
