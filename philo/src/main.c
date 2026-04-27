/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/27 18:29:22 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *myTurn(void *ptr)
{
	(void)ptr;
	int i = 0;
	while (i++ < 8)
	{
		sleep(1);
		printf("My turn %d\n", i);
	}
	return (NULL);
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

	pthread_create(&thread, NULL, myTurn, NULL);
	if (input_not_valid(ac, av))
		return (1);
	init_data(av, &data);
	// myTurn();
	yourTurn();
	pthread_join(thread, NULL);
	return (0);
}



