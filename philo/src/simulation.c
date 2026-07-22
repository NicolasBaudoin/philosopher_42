/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:28 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/22 11:30:54 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

int	solo_philo(t_philo *philo)
{
	if (philo->data->number_of_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		write_status(philo, "has taken a fork");
		update_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		update_sleep(philo->data->time_to_eat / 2);
	if (solo_philo(philo))
		return (NULL);
	while (!is_dead(philo->data))
	{
		if (philo_eat(philo))
			break ;
		if (is_dead(philo->data))
			break ;
		write_status(philo, "is sleeping");
		update_sleep(philo->data->time_to_sleep);
		if (is_dead(philo->data))
			break ;
		write_status(philo, "is thinking");
		if (philo->data->number_of_philo > 100)
			usleep(100);
		if (philo->data->number_of_philo % 2 != 0)
			usleep(500);
	}
	return (NULL);
}
// line 52 laisse le temps a l'os de redistribuer les fourchettes

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

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			if (check_starvation(data, &i))
				return (NULL);
			i++;
			if (i % 10 == 0)
				usleep(100);
		}
		if (check_nb_meal(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	simulation(t_data *data)
{
	pthread_t	*tids;
	pthread_t	monitor_tid;

	tids = malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!tids)
		return (1);
	if (pthread_create((&monitor_tid), NULL, monitor, data))
	{
		free(tids);
		return (1);
	}
	if (init_thread(data, tids))
	{
		free(tids);
		return (1);
	}
	join_tids(tids, data);
	pthread_join(monitor_tid, NULL);
	free(tids);
	return (0);
}
