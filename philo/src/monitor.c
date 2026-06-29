/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:48:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/06/20 15:27:24 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

int	check_starvation(t_data *data, int *i)
{
	long	last_meal;
	int		dead;

	pthread_mutex_lock(&data->meal_mutex);
	last_meal = data->philo[*i].time_last_meal;
	pthread_mutex_unlock(&data->meal_mutex);
	if (get_time() - last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->write_mutex);
		dead = data->dead;
		if (!dead)
		{
			data->dead = 1;
			ft_putnbr_fd(get_time() - data->start_time, 1);
			ft_putstr_fd(" ", 1);
			ft_putnbr_fd(data->philo[*i].id, 1);
			ft_putendl_fd(" died", 1);
		}
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
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
		if (data->philo[i].done)
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

void	join_tids(pthread_t *tids, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
}
