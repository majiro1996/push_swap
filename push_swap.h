/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 12:01:59 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//argv_check
int		ft_argv_check(char **argv, int parsed);
//cost
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_choose_cheapest(t_stack **stack_a, t_stack **stack_b);
//operation_ex
void	ft_operation_ex(t_stack **a, t_stack **b, int cost_a, int cost_b);
//operations
void	ft_rx(char x, t_stack **stack);
void	ft_rr(char mute, t_stack **stack_a, t_stack **stack_b);
void	ft_push_dx(char dx, t_stack **src, t_stack **dest);
void	ft_rrx(char x, t_stack **stack);
void	ft_rrr(char mute, t_stack **stack_a, t_stack **stack_b);
//op_swap
void	ft_sx(char x, t_stack *stack);
void	ft_ss(char mute, t_stack **stack_a, t_stack **stack_b);
//sort_three
void	ft_sort_three(t_stack **stack);
//sort
int		ft_is_sorted(t_stack *stack);
void	ft_sort_rest(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
//target
int		get_lowest_index_position(t_stack **stack);
void	ft_set_target_position(t_stack **a, t_stack **b);
//utils_2
t_stack	*ft_get_last(t_stack *stack);
t_stack	*ft_get_second_last(t_stack *stack);
t_stack	*ft_new_node(int value);
void	ft_add_stack_end(t_stack **stack, t_stack *new);
int		ft_get_stack_size(t_stack	*stack);
//fill_and_free
void	ft_free_stack(t_stack **stack);
t_stack	*ft_fill_stack(char **argv, int parsed);
void	ft_set_index(t_stack *stack_a, int stack_size);
//argv_parse
char	**ft_parse(char **argv);
int		ft_count_strings(char **strings);
void	ft_print_stack_values(t_stack *stack);
#endif
