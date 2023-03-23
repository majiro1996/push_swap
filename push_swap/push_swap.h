/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/03/23 19:10:39 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

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
t_stack		*ft_fill_stack(int ac, char **av);
void		ft_set_index(t_stack *stack_a, int stack_size);
//check_argv
int			nbstr_cmp(const char *s1, const char *s2);
static int	ft_is_number(char *s);
static int	have_duplicates(char **av);
static int	ft_is_zero(char *av);
int			is_correct_input(char **av);
//
#endif
