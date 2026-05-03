/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:03 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/03 13:20:45 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

// ===== @STRUCTURES =====

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long			time_last_meal;
	int				nb_meal_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_philo_must_eat;
	long			start_time;
	int				dead;
	int				philo_done;
	int				thread_alive;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_mutex;
	t_philo			*philo;

}				t_data;

// ===== @FUNCTIONS =====

// ==========
// @SRC
// ==========

// check input

int		input_not_valid(int ac, char **av);
void	display_error(char *str, int arg_pos, char *arg_value);
int		input_does_not_exist(char **av);
int		input_not_positive_or_too_high(char **av);
int		intput_not_number(char **av);

// init

int		init_data(char **av, t_data *data);
void	init_philo(t_data *data);
int		init_forks(t_data *data);
int		init_mutex(t_data *data);
int		init_malloc(t_data *data);
int		init_thread(t_data *data, pthread_t *tids);

// Simulation

int		simulation(t_data *data);
void	*routine(void	*arg);

// ==========
// Norme adaptation
// ==========

// routine

void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
int		eat_meal(t_philo *philo);
void	sleep_and_think(t_philo *philo);

// monitor

int		philo_done(t_data *data);
int		philo_starved_to_death(t_data *data, long *last_meal, int *i);

// simulation

void	wait_thread(t_data *data);

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
void	write_status(t_philo *philo, char *status);
long	get_time(void);
int		update_sleep(long miliseconds);
void	free_all(t_data *data);
int		is_dead(t_data *data);
void	set_dead(t_data *data);
void	write_output(t_data *data, int philo, char *output);
void	update_thread_alive(t_philo *philo);

#endif
