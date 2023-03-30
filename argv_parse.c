/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:59 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 21:02:28 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_strings(char **strings)
{
	int	count;

	count = 0;
	while (*strings != NULL)
	{
		strings++;
		count++;
	}
	return (count);
}

char	**ft_parse(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!*str)
		exit_error(NULL, NULL);
	return (str);
}
