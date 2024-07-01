/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:48:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/01 21:56:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo *philo;
	
	if (arg_parsing(argc, argv));
		return (1);
		
	memset(&arg, 0, sizeof(t_arg));//seteo la memoria reservada para 'arg' a 0
	
	if (arg_init())
		return (1);//per si falla el malloc o els mutex_init
	if (philo_init())
		return (1);//per si falla el malloc o els mutex_init

	

	start_simulation();
	//while que crea els threads =>start_action
	//check finish
	//while dels join

	clean();//per lliberar tots els mallocs i els mutex
		

	return (0);
}
