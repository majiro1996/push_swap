/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:59 by manujime          #+#    #+#             */
/*   Updated: 2023/04/03 12:23:54 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//counts the number of strings in a char**
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

/*splits the first argument into char** based on spaces*/
char	**ft_parse(char **argv)
{
	char	**str;

	if (!argv[1] || ft_strcmp(argv[1], "") == 0)
	{
		ft_printf("Error, nonvalid argument\n");
		exit(1);
	}
	str = ft_split(argv[1], ' ');
	if (!*str)
		exit(1);
	return (str);
}
