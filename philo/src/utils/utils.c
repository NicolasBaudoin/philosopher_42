/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:36:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 11:09:30 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		display_error("ft_strlen error", 0, NULL);
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned char	*cpy_nptr;
	int				nbr;
	int				sign;

	i = 0;
	cpy_nptr = (unsigned char *)nptr;
	nbr = 0;
	sign = 1;
	while ((cpy_nptr[i] >= 9 && cpy_nptr[i] <= 13) || cpy_nptr[i] == ' ')
		i++;
	if (cpy_nptr[i] == '-' || cpy_nptr[i] == '+')
	{
		if (cpy_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (cpy_nptr[i] >= '0' && cpy_nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (cpy_nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

long	ft_atol(char *args)
{
	long	value;
	int		sign;
	int		i;

	value = 0;
	sign = 1;
	i = 0;
	if (args[i] == '-' || args[i] == '+')
	{
		if (args[i] == '-')
			sign *= -1;
		i++;
	}
	while (args[i])
	{
		value = value * 10 + (args[i] - '0');
		i++;
	}
	return (value * sign);
}
