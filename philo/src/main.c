/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/29 14:37:30 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{

	t_data data;

	if (input_not_valid(ac, av))
		return (1);
	if (init_data(av, &data))
	{
		free_all(&data);
		return (1);
	}


	/*
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_time_philo_must_eat;
	long	start_time;
	int	dead;
	pthread_mutex_t	dead_mutex; -> reserve espace pour mettreo u non dead à 1;
	pthread_mutex_t	write_mutex; -> reserve espace pour ecrire sans avoir de print entre deux call imprevu
	pthread_mutex_t	*forks is forks[nbr_philo] with malloc
	-> here we can put forks left and right ?, exemple
	4 philos → 4 fourchettes

	forks[0]  entre philo 1 et philo 2
	forks[1]  entre philo 2 et philo 3
	forks[2]  entre philo 3 et philo 4
	forks[3]  entre philo 4 et philo 1

	philo[i].left_fork  = &forks[i]
	philo[i].right_fork = &forks[(i+1) % nb_philos]

	t_philo	*philo is philo[nbr_philo] with malloc

	*/


	// pthread_create(&thread, NULL, myTurn, NULL);
	return (0);
}



