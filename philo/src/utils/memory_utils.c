/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:01:29 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 10:02:13 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_all(t_data *data)
{
	int i;

	// 1. destroy mutex des forks
	i = 0;
	if (data->forks)
	{
		while (i < data->number_of_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
		pthread_mutex_destroy(&data->write_mutex);
		pthread_mutex_destroy(&data->dead_mutex);
		pthread_mutex_destroy(&data->meal_mutex);
	}
	// 3. free les philos
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
}
