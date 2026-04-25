/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:19:05 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/25 17:38:35 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_not_valid(int ac, char **av)
{
	if (ac < 4 || ac > 5)
	{
		display_error("Program takes four or five arguments");
		return (1);
	}
	input_not_positive_or_too_high(av);
	return (0);
}

int	input_not_positive_or_too_high(char **av)
{
	int	i;

	i = 0;
	while (ft_atoi(av[i]))
	{

	}
	return 0;
}