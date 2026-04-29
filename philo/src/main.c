/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/29 12:16:17 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *myTurn(void *ptr)
// {
// 	(void)ptr;
// 	int	*nbr_philo = (int *)malloc(sizeof(int));
// 	int i = 0;
// 	while (i++ < 8)
// 	{
// 		sleep(1);
// 		ft_write_printf("myTurn : ", i, " ", 1, 1);
// 		(*nbr_philo)++;
// 	}
// 	return (nbr_philo);
// }

// void  yourTurn()
// {
// 	int i = 0;
// 	while (i++ < 3)
// 	{
// 		sleep(2);
// 		ft_write_printf("Your turn :",i, " ", 1, 1 );
// 	}
// }

int	main(int ac, char **av)
{

	t_data data;

	if (input_not_valid(ac, av))
		return (1);
	init_data(av, &data);
	// pthread_create(&thread, NULL, myTurn, NULL);
	// // myTurn();
	// yourTurn();
	// pthread_join(thread, (void *)&result);
	// ft_write_printf("Thread finished : ", *result, " ", 1, 1);
	// // printf("thread finished : %d\n", *result);
	return (0);
}



