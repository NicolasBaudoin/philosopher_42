/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:37 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/25 17:37:06 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (input_not_valid(ac, av))
		return (1);
	int n = 2;
	// input_not_valid(ac, av);
	int id = fork();
	n+= 3;
	int id2 = fork();
	n += 3;

	n = 9;
	printf("id1 %d | id2 %d | n = %d\n", id, id2, n);


	return (0);
}
