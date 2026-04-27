/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:20:55 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/27 11:19:28 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_error(char *error_msg, int arg_pos, char *arg_value)
{
	char *truc;
	ft_putendl_fd("Error", 2);
	if (arg_pos != 0)
	{
		truc = "Arg n° ";
		ft_putstr_fd(truc, 2);
		ft_putnbr_fd(arg_pos, 2);
		ft_putstr_fd(" : ", 2);
	}
	if (arg_value)
	{
		ft_putstr_fd(arg_value, 2);
	}
	ft_putendl_fd(error_msg, 2);
}
