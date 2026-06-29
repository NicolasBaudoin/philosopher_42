/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:49:28 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/06/20 15:20:33 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->write_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->write_mutex);
}

int	is_dead(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->write_mutex);
	dead = data->dead;
	pthread_mutex_unlock(&data->write_mutex);
	return (dead);
}
