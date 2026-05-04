/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:46:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 14:18:05 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	wait_thread(t_data *data)
{
	long start;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->thread_alive == 0)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->meal_mutex);
		if (get_time() - start > 100)
			break ;
		usleep(100);
	}

}
