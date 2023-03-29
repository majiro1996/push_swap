/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:59 by manujime          #+#    #+#             */
/*   Updated: 2023/03/30 01:43:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_strings(char **strings) {
    int count = 0;
    while (*strings != NULL) {
        count++;
        strings++;
    }
    return (count);
}

void	ft_parse(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!*str)
		exit_error(NULL, NULL);
}
