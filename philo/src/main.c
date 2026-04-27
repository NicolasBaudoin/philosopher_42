/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/27 18:50:03 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *myTurn(void *ptr)
{
	(void)ptr;
	int	*nbr_philo = (int *)malloc(sizeof(int));
	int i = 0;
	while (i++ < 8)
	{
		sleep(1);
		printf("My turn %d nb : %d\n", i, *nbr_philo);
		(*nbr_philo)++;
	}
	return (nbr_philo);
}

void  yourTurn()
{
	int i = 0;
	while (i++ < 3)
	{
		sleep(2);
		printf("Your turn %d\n", i);
	}
}

int	main(int ac, char **av)
{
	t_data data;
	pthread_t thread;

	int *result = NULL;

	if (input_not_valid(ac, av))
		return (1);
	init_data(av, &data);
	pthread_create(&thread, NULL, myTurn, NULL);
	// myTurn();
	yourTurn();
	pthread_join(thread, (void *)&result);
	printf("thread finished : %d\n", *result);
	return (0);
}



