/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:37:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/01 11:53:08 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>


void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	while (!is_dead(philo->data))
	{
		write_status(philo, "is sleeping...");

		write_status(philo, "is thinking...");
	}
	// think, eat, sleep, redo;
	// think : X is thinking...
	// sleep for data.time_to_sleep time with ft_usleep
	/* for eating : lock right fork, print message; then lock left fork, print message;
	then he will eat using ft_usleep; then he will drp forks by unlocking;
	dont forget to change variable*/
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

	tids = malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!tids)
		return (1);
	if (init_thread(data, tids))
	{
		free(tids);
		return (1);
	}
	usleep(20000);
	set_dead(data);
	int i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
	free(tids);
	return (0);
}
