/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:03 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/27 13:51:02 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# include <stdio.h>

// ===== @MACROS =====

// ===== @STRUCTURES =====

typedef struct s_philo
{
	int	pid;
	int	time_last_meal;
	int	status;
}				t_philo;

typedef struct s_data
{
	int	philo_feedback_state;
	int	time_to_sleep;
}				t_data;

// ===== @FUNCTIONS =====

// ==========
// @PARSING
// ==========

int		input_not_valid(int ac, char **av);
void	display_error(char *str, int arg_pos, char *arg_value);
int		input_does_not_exist(char **av);
int		input_not_positive_or_too_high(char **av);
int		intput_not_number(char **av);

// ==========
// @UTILS
// ==========

int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(char *args);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif