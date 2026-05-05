/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:48:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/05 12:00:27 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

int	check_starvation(t_data *data, int *i)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (get_time() - data->philo[*i].time_last_meal > data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		write_status(&data->philo[*i], "died");
		set_dead(data);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

int	check_nb_meal(t_data *data)
{
	int	i;
	int	done;

	if (data->nb_time_philo_must_eat == 0)
		return (0);
	i = 0;
	done = 0;
	pthread_mutex_lock(&data->meal_mutex);
	while (i < data->number_of_philo)
	{
		if (data->philo[i].nb_meal_eaten >= data->nb_time_philo_must_eat)
			done++;
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	if (done == data->number_of_philo)
	{
		set_dead(data);
		return (1);
	}
	return (0);
}