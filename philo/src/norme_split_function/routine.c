/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:03:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 14:27:56 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_fork(t_philo *philo, int fork_to_unlock)
{
	if (is_dead(philo->data))
	{
		if (fork_to_unlock == 1)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		else if (fork_to_unlock == 2)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		else if (fork_to_unlock == 3)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
	}
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (dead_fork(philo, 1))
			return (1);
		write_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (dead_fork(philo,3))
			return (1);
		write_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (dead_fork(philo, 2))
			return (1);
		write_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (dead_fork(philo, 3))
			return (1);
		write_status(philo, "has taken a fork");
	}
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->time_last_meal = get_time();
	philo->nb_meal_eaten++;
	if (philo->data->nb_time_philo_must_eat > 0 && philo->nb_meal_eaten
		>= philo->data->nb_time_philo_must_eat)
	{
		philo->data->philo_done++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		write_status(philo, "is eating");
		update_sleep(philo->data->time_to_eat);
		drop_forks(philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	write_status(philo, "is eating");
	update_sleep(philo->data->time_to_eat);
	drop_forks(philo);
	if (is_dead(philo->data))
        return (1);
	return (0);
}

void	sleep_and_think(t_philo *philo)
{
	write_status(philo, "is sleeping");
	update_sleep(philo->data->time_to_sleep);
	write_status(philo, "is thinking");
	usleep(500);
}
