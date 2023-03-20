/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:44:49 by manujime          #+#    #+#             */
/*   Updated: 2023/03/20 15:46:10 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include<stddef.h>

typedef struct s_stack
{
    int     *array;
    int     size;
    int     capacity;
}   t_stack;

void    initialize_stacks(t_stack *a, t_stack *b, int argc, char **argv);
void    free_stacks(t_stack *a, t_stack *b);
int     is_sorted(t_stack *a);
void	sort(t_stack *stack_a, t_stack *stack_b);
void    swap(t_stack *stack, char c);
void    reverse_rotate(t_stack *stack, char c);
void    rotate(t_stack *stack, char c);
void    push(t_stack *dest, t_stack *src, char c);
void    sort_three_or_less(t_stack *a, t_stack *b);
void    sort_five_or_less(t_stack *a, t_stack *b);
void    sort_larger_than_five(t_stack *a, t_stack *b);
int     find_median(t_stack *stack, int size);
int     find_smallest(t_stack *stack);
int     get_chunk(t_stack *stack, int chunk_num, int n_chunks);
int     get_n_chunks(int stack_size);
int     ft_strlen(const char *s);
void    ft_putendl_fd(char *s, int fd);

#endif
