/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:25 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/06/20 15:09:53 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (input_not_valid(ac, av) || init_data(av, &data))
		return (1);
	if (simulation(&data))
	{
		free_all(&data);
		return (1);
	}
	free_all(&data);
	return (0);
}
