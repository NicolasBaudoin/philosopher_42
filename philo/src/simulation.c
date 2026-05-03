/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:37:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 10:09:43 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	solo_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, "has taken a fork");
	update_sleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;
	long	last_meal;

	data = (t_data *)arg;

	while (!is_dead(data))
	{
		i = 0;
		if (sim_is_over(data))
			return (NULL);
		while (i < data->number_of_philo)
		{
			pthread_mutex_lock(&data->meal_mutex);
			last_meal = data->philo[i].time_last_meal;
			pthread_mutex_unlock(&data->meal_mutex);
			// vérifie si ce philo a dépasser time to die
			pthread_mutex_lock(&data->dead_mutex);
			if (get_time() - last_meal > data->time_to_die)
			{
				write_status(&data->philo[i], "died");
				data->dead = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->dead_mutex);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id%2 == 0)
		usleep(1000);
	// 1 philo case
	if (philo->data->number_of_philo == 1)
	{
		solo_philo(philo);
		return (NULL);
	}
	// other cases
	while (!is_dead(philo->data))
	{
		// pair
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right_fork);
			write_status(philo, "has taken a fork");
			pthread_mutex_lock(philo->left_fork);
			write_status(philo, "has taken a fork");
		}
		// impair
		else
		{
			pthread_mutex_lock(philo->left_fork);
			write_status(philo, "has taken a fork");
			pthread_mutex_lock(philo->right_fork);
			write_status(philo, "has taken a fork");
		}
		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->time_last_meal = get_time();
		philo->nb_meal_eaten++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		write_status(philo, "is eating");
		update_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		// sleep
		write_status(philo, "is sleeping");
		update_sleep(philo->data->time_to_sleep);

		// think
		write_status(philo, "is thinking");
	}
	return (NULL);
}

int	init_thread(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_create(&tids[i], NULL, routine, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	simulation(t_data *data)
{
	pthread_t	*tids;
	pthread_t	monitor_tid;
	int			i;

	tids = malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!tids)
		return (1);
	if (init_thread(data, tids))
	{
		free(tids);
		return (1);
	}
	// launch monitor
	pthread_create(&monitor_tid, NULL, monitor, data);

	// wait monitor
	pthread_join(monitor_tid, NULL);

	// wait philos
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
	free(tids);
	return (0);
}
