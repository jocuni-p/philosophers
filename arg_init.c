/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:53:32 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/01 21:46:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//arg init
//hacer mallocs a quien necesite
//philo init
//mallocar quien necesite
int	arg_init(int argc, char *argv[], t_arg *arg)
{
	
	arg->philo_num = atoi(argv[1]);
	arg->time_to_die = atoi(argv[2]);
	arg->time_to_eat = atoi(argv[3]);
	arg->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		arg->min_eat_times = atoi(argv[5]);


}