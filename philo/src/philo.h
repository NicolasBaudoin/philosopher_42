/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:03 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/29 12:11:45 by nbaudoin         ###   ########.fr       */
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
	// int	time_until_death;
	// int	time_last_meal;
	// int	status;
	// int	nb_meal_eaten;
	// pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
}				t_philo;

typedef struct s_data
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_time_philo_must_eat;
	long	start_time;
	// pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks;
	t_philo	*philo;

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

// init

void	init_data(char **av, t_data *data);

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
void	ft_write_printf(char *msg_before_var, int var, char *msg_after_var,
	int endline, int fd);


// @test
void  yourTurn();
void  *myTurn(void *ptr);

#endif