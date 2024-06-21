/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:46:16 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/21 12:41:38 by jocuni-p         ###   ########.fr       */
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



//Declaracio de variables
typedef struct s_pack
{
	int				nbr_philos;
	int				i;//SACAR ESTE ITERADOR DE AQUI
	int				target;
	struct timeval	start;//declaro la var/struct que contendra el temps en que comencem a comptar
	struct timeval	parcial;//declaro la struct del tiempo que la contiene la libreria 
	pthread_mutex_t locker;//declaro el mutex
}					t_pack;


typedef struct s_general
{
	t_pack	*pack;
	int		philonum;
} 			t_general;

void	*routine1(void *arg);
void	init_pack(t_pack *pack, char *argv[]);
double 	time_diff_millis(struct timeval *start, struct timeval *end);




#endif
