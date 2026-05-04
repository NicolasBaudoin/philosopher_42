/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 14:24:43 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		sim;

	if (input_not_valid(ac, av))
		return (1);
	if (init_data(av, &data))
		return (1);
	sim = simulation(&data);
	// free_all(&data);
	return (sim);
}
