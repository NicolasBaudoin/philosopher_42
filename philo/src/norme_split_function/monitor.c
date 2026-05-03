/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:48:47 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 14:22:24 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_done(t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (data->nb_time_philo_must_eat > 0 && data->philo_done
		>= data->number_of_philo)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		set_dead(data);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

void	update_last_meal(t_data *data, long *last_meal, int *i)
{
	pthread_mutex_lock(&data->meal_mutex);
	*last_meal = data->philo[*i].time_last_meal;
	pthread_mutex_unlock(&data->meal_mutex);
}

int	philo_starved_to_death(t_data *data, long *last_meal, int *i)
{
	if (get_time() - *last_meal >= data->time_to_die)
	{
		pthread_mutex_lock(&data->write_mutex);
		data->dead = 1;
		write_output(data, data->philo[*i].id, " died\n");
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	return (0);
}
