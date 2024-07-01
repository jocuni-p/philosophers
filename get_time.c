/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:34:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/30 10:59:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Returns the current time in miliseconds*/
long long	get_time(void)
{
	struct timeval	tv;

	if(gettimeofday(&tv, NULL))
	{
		printf("Error. 'gettimeofday' failed.\n");
		return (1);//No se si vale la pena retornar el error de esta funcion???
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
