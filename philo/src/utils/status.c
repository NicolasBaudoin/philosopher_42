/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:31:42 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 10:01:26 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_dead(t_data *data)
{
	int	dead;
	pthread_mutex_lock(&data->dead_mutex);
	dead = data->dead;
	pthread_mutex_unlock(&data->dead_mutex);
	return (dead);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
}

int	sim_is_over(t_data *data)
{
	int	i;
	int	count_meal;

	if (!data->nb_time_philo_must_eat)
		return (0);
	count_meal = 0;
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->philo[i].nb_meal_eaten >= data->nb_time_philo_must_eat)
			count_meal++;
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
	if (count_meal == data->number_of_philo)
	{
		set_dead(data);
		return (1);
	}
	return (0);
}
