/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:42:25 by manujime          #+#    #+#             */
/*   Updated: 2023/03/22 15:42:30 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//input_check// input_check_utils//

static int	ft_is_number(char *s)
{
	int	c;

	c = 0;
	if (is_sign(s[c]) && s[c + 1] != '\0')
		c++;
	while (s[c] && (s[c] >= '0' && s[c] <= '9'))
		c++;
	if (s[c] != '\0' && (s < '0' && s > '9'))
		return (0);
	return (1);
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] ==  '-' || av[i] == '+')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_is_number(av[i]))
			return (0);
		nb_zeros += ft_is_zero(av[i]);
		i++;
	}
	if (have_duplicates(av) || nb_zeros > 1)
		return (0);
	return (1);
}
