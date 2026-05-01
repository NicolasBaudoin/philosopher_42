/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:37:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/01 10:43:59 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation(t_data *data)
{
	pthread_t	*tids;

	tids = malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!tids)
		return (1);
	free(tids);
	return (0);
}
