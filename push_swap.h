/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/03/31 15:44:17 by manujime         ###   ########.fr       */
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

//main

//argv_parse
char		**parse_args(char **argv, int argc);
int			count_words(char *str);
char		*find_next_word(char *str);
char		*find_next_space(char *str);
char		*trim_left(char *str);
//argv_check
int			ft_nbr_str_cmp(const char *s1, const char *s2);
int			ft_is_number(char *s);
int			have_duplicates(char **av);
int			ft_argv_check(char **argv, int parsed);
//cost
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
//operation_ex
void		do_rev_rotate_both(t_stack **a, t_stack **b,
				int *cost_a, int *cost_b);
void		do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		do_rotate_a(t_stack **a, int *cost);
void		do_rotate_b(t_stack **b, int *cost);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
//operations
void		ft_rx(char x, t_stack **stack);
void		ft_rr(char mute, t_stack **stack_a, t_stack **stack_b);
void		ft_push_dx(char dx, t_stack **src, t_stack **dest);
void		ft_rrx(char x, t_stack **stack);
void		ft_rrr(char mute, t_stack **stack_a, t_stack **stack_b);
//swap
void		ft_sx(char x, t_stack *stack);
void		ft_ss(char mute, t_stack **stack_a, t_stack **stack_b);
//sort_2
int			find_highest_index(t_stack *stack);
void		ft_sort_three(t_stack **stack);
//sort
void		push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void		shift_stack(t_stack **stack_a);
int			ft_is_sorted(t_stack *stack);
void		ft_sort_rest(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
//target
void		get_position(t_stack **stack);
int			get_lowest_index_position(t_stack **stack);
int			get_target(t_stack **a, int b_idx,
				int target_idx, int target_pos);
void		get_target_position(t_stack **a, t_stack **b);
//utils_2
t_stack		*ft_get_last(t_stack *stack);
t_stack		*ft_get_second_last(t_stack *stack);
t_stack		*ft_new_node(int value);
void		ft_add_stack_end(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);
//utils
void		ft_free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_fill_stack(char **argv, int parsed);
void		ft_set_index(t_stack *stack_a, int stack_size);
//parse
char		**ft_parse(char **argv);
int			ft_count_strings(char **strings);
void		ft_print_stack_values(t_stack *stack);
#endif
