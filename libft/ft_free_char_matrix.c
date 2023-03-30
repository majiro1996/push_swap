/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:49:23 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 14:53:39 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
//frees all memory of a char ** 
void	ft_free_char_matrix(char **arr)
{
	char	**current;

	if (arr == NULL)
		return ;
	current = arr;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(arr);
}
