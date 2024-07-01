/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:39:51 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/21 11:50:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_pack		*pack;//Declaro la struct
//	t_general	*general;
	pthread_t	*thread;//Array de threads/philos

	
	if (argc < 2)
	{
		printf("Debes pasar como arg el numero de filosofos.\n");
		return (0);
	}

	pack = malloc(sizeof(t_pack));// Asigno memoria para la struct
	if (pack == NULL)
	{
		perror("Error al asignar memoria");
		return (-1);
	}

	init_pack(pack, argv);//inicializo las vars

	pthread_mutex_init(&(pack->locker), NULL);//inicializo mutex (suposo que tambe podria estar dins init_pack)

//	general = malloc(pack->nbr_philos * sizeof(general));


	thread = malloc(pack->nbr_philos * sizeof(pthread_t));//Alojo memoria para el array de threads

	if (gettimeofday(&pack->start, NULL) == -1)//tomamos el tiempo de inicio y lo ponemos en 'start'
	{
		printf("ha fallado la funcion del tiempo\n");
		return (1);
	}	

	while (pack->nbr_philos > pack->i)
	{
		if (pthread_create(&thread[pack->i], NULL, &routine1, (void *)pack) != 0)//Crea todos los hilos
//		if (pthread_create(thread + pack->i, NULL, routine1, (void *)pack) != 0)//Es el mateix que a dalt
		{
			printf("ha fallado la creacion del hilo%i.\n", pack->i);//aviso por si falla
			return (-1);
		}
		printf("Created el philo%i\n", pack->i);
		pack->i++;
	}

	pack->i = 0;

	while (pack->nbr_philos > pack->i)//Crea els joins dels threads, es molt possible que els threads acabin abans que els joins els recullint, perque aquests els esperen per ordre.
	{
		if (pthread_join(thread[pack->i], NULL) != 0)//No avanza hasta que el hilo se ha unido/juntado.
		{
			printf("ha fallado la espera del hilo%i.\n", pack->i);
			return (-1);
		}
		printf("Joined el philo%i\n", pack->i);
		pack->i++;
	}
	pthread_mutex_destroy(&(pack->locker));//limpia todos los recursos asociados al mutex
	return (0);
}
/*TO DO:::::::::
2.IMPLEMENTAR LA STRUCT QUE EM PERMET SABER EL NUM DE THREAD Y PER ON HA PASSAT (REVISAR CHATgpt 'THREADS Y MUTEX')
3.POSAR ENTRE ELS CREATES I ELS JOINS UNA FUNCIO OBSERVADORA QUE SI DETECTA UNA MORT TANCA BE EL PROGRAMA*/
//Posar dins del mutex les 2 forquilles i despres per un temps x (usleep amb microsegons del arguments).