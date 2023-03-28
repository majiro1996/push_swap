/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:42:25 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 13:38:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//input_check// input_check_utils//

int	ft_nbr_str_cmp(const char *s1, const char *s2)
{
	while (*s1 == '+')
		s1++;
	while (*s2 == '+')
		s2++;
	return (ft_strcmp(s1, s2));
}

int	ft_is_number(char *s)
{
	int	c;

	c = 0;
	if ((s[c] == '+' || s[c] == '-') && s[c + 1])
		c++;
	while (s[c] && (s[c] >= '0' && s[c] <= '9'))
		c++;
	if (s[c] != '\0' && (s[c] < '0' && s[c] > '9'))
		return (0);
	return (1);
}

int	ft_dups(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_nbr_str_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_argv_check(char **argv)
{
	int	i;
	int	zero_dups;

	zero_dups = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]))
			return (0);
		if (ft_atol(argv[i]) == 0)
			zero_dups++;
		i++;
	}
	if (ft_dups(argv) || zero_dups > 1)
		return (0);
	return (1);
}