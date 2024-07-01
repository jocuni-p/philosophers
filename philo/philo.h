/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:46:16 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/01 17:46:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

/*---Colors----*/
# define BLUE "\x1B[34m"
# define YELLOW "\x1B[33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define RESET "\x1B[0m"
# define PINK "\x1B[95m"
# define DIED 0
# define EATING 1
# define THINKING 2
# define FORK 3
# define SLEEPING 4
# define FINISHED 5

# define EXIT_FAILURE 1

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef pthread_mutex_t t_mtx;

/*--general struct--*/
typedef struct s_arg
{
	int			philo_num;
	long int	time_to_die;//miliseconds
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	min_eat_times;// [optional param]
	long long	start_time;//begining of the simulation
	bool		finish;//1 is true, 0 is false
	t_mtx		finish_mtx;//No estic segur si l'he de protegir amb mutex???
	int			finished_eat;//nbr of philos that accomplished their meals
	t_mtx		synchro_mtx;//Initial threads synchroniser
}				t_arg;

/*---every 'philo' has its own struct---*/
typedef struct s_philo
{
	t_arg		*arg;//reference to t_arg struct
	pthread_t	thread;//que contiene??
	int			id;
	int			first_fork;//numero de tenedor del philo
	int			second_fork;//numero de tenedor del siguiente philo
	int			meals_counter;//numero de comidas hechas por este philo
	long long	last_eat_time;//time since the last meal
	t_mtx		last_eat_time_mtx;
}				t_philo;

/*----------parsing-----------*/
int	arg_parsing(int argc, char *argv[]);
int	arg_limits(char *str, int i);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);




#endif
