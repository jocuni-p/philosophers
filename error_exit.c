/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:49:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/30 11:54:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CREO QUE PUEDO PRESCINDIR, NO APORTA NADA
#include "philo.h"

void	error_exit(const char *error)
{
	printf(RED"%s\n"RESET, error);
	return (1);
}