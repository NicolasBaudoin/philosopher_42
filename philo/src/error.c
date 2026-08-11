/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:29:31 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/08/12 01:33:35 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	display_error(char *error_msg, int arg_pos, char *arg_value)
{
	char	*arg;

	ft_putendl_fd("Error", 2);
	if (arg_pos != 0)
	{
		arg = "Arg n° ";
		ft_putstr_fd(arg, 2);
		ft_putnbr_fd(arg_pos, 2);
		ft_putstr_fd(" : ", 2);
	}
	if (arg_value)
	{
		ft_putstr_fd(arg_value, 2);
	}
	ft_putendl_fd(error_msg, 2);
}
