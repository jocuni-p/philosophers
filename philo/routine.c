/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:02:16 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/21 12:02:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine1(void *arg)
{
	t_pack	*pack_tmp;//es solo para recibir el arg casteado.
	pack_tmp = (t_pack *)arg;
	//aqui la funcion que toma el tiempo parcial i calcula la diferencia
	pthread_mutex_lock(&pack_tmp->locker);//Bloqueo la zona critica para que no accedan 2 hilos a la misma vez.
	pack_tmp->target += 2;//seteo la variable
	gettimeofday(&pack_tmp->parcial, NULL);
	printf("%f | philo%d | target=%i\n", time_diff_millis(&pack_tmp->start, &pack_tmp->parcial), pack_tmp->i, pack_tmp->target);
	pthread_mutex_unlock(&pack_tmp->locker);
	return NULL;
}
