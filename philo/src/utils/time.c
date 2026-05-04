/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:55:27 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 15:04:40 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

int	update_sleep(long miliseconds, t_data *data)
{
	long	now;

	now = get_time();
	while (get_time() - now < miliseconds)
	{
		if (data && is_dead(data))
			return (1);
		usleep(200);
	}
	return (1);
}
