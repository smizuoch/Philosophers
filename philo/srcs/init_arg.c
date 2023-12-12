/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:51:09 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/12 15:40:24 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_arg(int argc, char **argv, t_arg *arg)
{
	if (check_arg(argc, argv))
		return (1);
	arg->number_of_philosophers = philo_atoi(argv[1]);
	if (arg->number_of_philosophers <= 0)
		return (1);
	arg->time_to_die = philo_atoi(argv[2]);
	if (arg->number_of_philosophers <= 0)
		return (1);
	arg->time_to_eat = philo_atoi(argv[3]);
	if (arg->time_to_eat <= 0)
		return (1);
	arg->time_to_sleep = philo_atoi(argv[4]);
	if (arg->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		arg->number_of_times_each_philosopher_must_eat = philo_atoi(argv[5]);
		if (arg->number_of_times_each_philosopher_must_eat <= 0)
			return (1);
	}
	return (0);
}
