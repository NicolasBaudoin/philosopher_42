/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:43:18 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 12:32:50 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_last_meal = data->start_time;
		data->philo[i].nb_meal_eaten = 0;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1)
			% data->number_of_philo];
		data->philo[i].data = data;
		i++;
	}
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->dead_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (1);
	if (init_forks(data))
		return (1);
	return (0);
}

int	init_malloc(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->forks)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philo)
	{
		free(data->forks);
		data->forks = NULL;
		return (1);
	}
	return (0);
}

int	init_data(char **av, t_data *data)
{
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->philo_done = 0;
	data->thread_alive = data->number_of_philo;
	if (!av[5] || !av[5][0])
		data->nb_time_philo_must_eat = 0;
	else
		data->nb_time_philo_must_eat = ft_atoi(av[5]);
	data->dead = 0;
	if (init_malloc(data))
		return (1);
	if (init_mutex(data))
	{
		free_all(data);
		return (1);
	}
	data->start_time = get_time();
	init_philo(data);
	return (0);
}
