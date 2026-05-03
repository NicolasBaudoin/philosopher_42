/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:37:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 14:30:00 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	solo_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, "has taken a fork");
	update_sleep(philo->data->time_to_die);
	write_status(philo, "died");
	set_dead(philo->data);
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
		while (i < data->number_of_philo)
		{
			if (philo_done(data))
				return (NULL);
			update_last_meal(data, &last_meal, &i);
			pthread_mutex_lock(&data->dead_mutex);
			if (philo_starved_to_death(data, &last_meal, &i))
			{
				pthread_mutex_unlock(&data->dead_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->dead_mutex);
			i++;
		}
		usleep(200);
	}
	return (NULL);
}

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	if (philo->data->number_of_philo == 1)
	{
		solo_philo(philo);
		update_thread_alive(philo);
		return (NULL);
	}
	while (!is_dead(philo->data))
	{
		wait_for_forks(philo);
		usleep(100);
		take_forks(philo);
		if (eat_meal(philo))
		{
			update_thread_alive(philo);
			return (NULL);
		}
		sleep_and_think(philo);
	}
	update_thread_alive(philo);
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
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_detach(tids[i]);
		i++;
	}
	pthread_create(&monitor_tid, NULL, monitor, data);
	pthread_join(monitor_tid, NULL);
	wait_thread(data);
	free(tids);
	return (0);
}
