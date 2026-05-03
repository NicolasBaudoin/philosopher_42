/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:19:05 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 13:30:08 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_not_valid(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		display_error("invalid arguments, program takes four or five arguments",
			0, NULL);
		return (1);
	}
	if (input_does_not_exist(av))
		return (1);
	if (input_not_positive_or_too_high(av))
		return (1);
	if (intput_not_number(av))
		return (1);
	return (0);
}

int	input_does_not_exist(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i] || !av[i][0])
		{
			display_error(" is invalid", i, av[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	input_not_positive_or_too_high(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (atol(av[i]) <= 0 || atol(av[i]) > INT_MAX)
		{
			display_error(" is invalid", i, av[i]);
			return (1);
		}
		if (ft_atol(av[1]) > 200)
		{
			display_error(" is invalid, we dont verify over 200", 1, av[1]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	intput_not_number(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				display_error(" is invalid number", i, av[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
