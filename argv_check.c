/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:42:25 by manujime          #+#    #+#             */
/*   Updated: 2023/04/04 11:53:15 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*checks if two arguments are the same*/
int	ft_nbr_str_cmp(const char *s1, const char *s2)
{
	while (*s1 == '+' || *s1 == '0')
		s1++;
	while (*s2 == '+' || *s2 == '0')
		s2++;
	return (ft_strcmp(s1, s2));
}

/*checks if an argument is a number*/
int	ft_is_number(char *s)
{
	int	c;

	c = 0;
	if (s[c] && (s[c] == '+' || s[c] == '-'))
		c++;
	while (s[c])
	{
		if (!ft_isdigit(s[c]))
			return (0);
		c++;
	}
	return (1);
}

/*checks if there are duplicated arguments*/
int	ft_dups(char **argv)
{
	int	i;
	int	j;
	int	zero;

	zero = 0;
	i = 1;
	while (argv[i])
	{
		j = 1;
		if (ft_atol(argv[i]) == 0)
			zero++;
		while (argv[j])
		{
			if ((j != i && ft_nbr_str_cmp(argv[i], argv[j]) == 0) || zero > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*cheks if the arguments are correct*/
int	ft_argv_check(char **argv, int parsed)
{
	int			i;
	long int	nbr;

	nbr = 0;
	i = parsed;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		if (!ft_is_number(argv[i]))
			return (0);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	if (ft_dups(argv))
		return (0);
	return (1);
}
