/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:51:09 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/20 09:10:14 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_arg(int argc, char **argv, t_config *config)
{
	config->number_of_times_each_philosopher_must_eat = -1;
	if (check_arg(argc, argv))
		return (1);
	config->number_of_philosophers = philo_atoi(argv[1]);
	if (config->number_of_philosophers <= 0
		|| config->number_of_philosophers > 200)
		return (1);
	config->time_to_die = philo_atoi(argv[2]);
	if (config->number_of_philosophers <= 0)
		return (1);
	config->time_to_eat = philo_atoi(argv[3]);
	if (config->time_to_eat <= 0)
		return (1);
	config->time_to_sleep = philo_atoi(argv[4]);
	if (config->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		config->number_of_times_each_philosopher_must_eat = philo_atoi(argv[5]);
		if (config->number_of_times_each_philosopher_must_eat <= 0)
			return (1);
	}
	return (0);
}

/*
An error is generated for more than 400 threads,
as the practical limit for thread creation
is between 200 and 400.
See below for reference.

https://www.ibm.com/docs/ja/zos/3.1.0
?topic=functions-pthread-create-create-thread
*/
