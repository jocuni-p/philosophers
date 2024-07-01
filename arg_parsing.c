/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:13:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/01 17:55:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	flag;

	i = 0;
	nbr = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		nbr = -nbr;
	return (nbr);
}

int	arg_limits(char *str, int i)
{
	int	nbr;

	nbr = atoi(str);
	if (i == 1 && (nbr < 0 || nbr > PHILO_MAX))
	{
		printf(RED "Error. 'philo_num' param has to be min 1 \
		and max 200.\n" RESET);
		return (1);
	}
	if (i >= 2 && i <= 4)
	{
		if (nbr < 60 & nbr > INT_MAX)
		{
			printf(RED "Error.\n Do not test values bellow \
			than 60 ms.\n" RESET);
			printf(RED " Do not test values above INT_MAX.\n" RESET);
			return (1);
		}
	}
	if (i == 5 && nbr > INT_MAX)
	{
		printf(RED "Error. Do not test values above INT_MAX.\n" RESET);
		return (1);
	}
	return (0);
}

/*Checks for nbr of args, digit, positive and arg limits*/
int	arg_parsing(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf(RED "Wrong number of arguments.\n Usage is \
		./philo N_philosophers time_to_die time_to_eat time_to_sleep \
		optional[min_nb_meals]\n" RESET);
		return (1);
	}
	while (argv[++i])
	{
		if (ft_isdigit(argv[i] == 0))
		{
			printf(RED "Error. All arguments must contain digits.\n" RESET);
			return (1);	
		}
		if (atoi(argv[i]) <= 0)
		{
			printf(RED "Error. All arguments must be greater than 0." RESET);
			return (1);
		}
		if (arg_limits(argv[i], i))
			return (1);
	}
}
