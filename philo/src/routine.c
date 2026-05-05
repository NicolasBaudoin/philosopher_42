/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:15:29 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/05 15:33:26 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	philo_eat(t_philo *philo)
{
	if (is_dead(philo->data))
		return (1);
	pthread_mutex_lock(&philo->data->meal_mutex);
	if (philo->data->nb_time_philo_must_eat > 0 && philo->nb_meal_eaten >= philo->data->nb_time_philo_must_eat)
	{
		philo->done = 1;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		write_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		write_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		write_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		write_status(philo, "has taken a fork");
	}
	if (is_dead(philo->data))
	{
		drop_forks(philo);
		return (1);
	}
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->time_last_meal = get_time();
	philo->nb_meal_eaten++;
	if (philo->data->nb_time_philo_must_eat > 0
    && philo->nb_meal_eaten >= philo->data->nb_time_philo_must_eat)
    philo->done = 1;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	write_status(philo, "is eating");
	update_sleep(philo->data->time_to_eat);
	drop_forks(philo);
	return (0);
}
