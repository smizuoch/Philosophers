/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:53:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/07 17:09:27 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosopher_function(t_philo *philo)
{
	while (get_time() < philo->config->start_time)
		usleep(10);
	philo->last_meal_time = get_time();
	while (1)
	{
		take_fork(philo);
		do_eat(philo);
		do_sleep(philo);
		do_think(philo);
	}
	return (0);
}

int	start_life(t_config *config, t_philo *philosophers)
{
	int	i;

	i = 0;
	config->start_time = get_time() + 1000;
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
				(void *)philosopher_function, &philosophers[i]) != 0)
			return (return_error());
		i ++;
	}
	observer(config);
	i = 0;
	while (i < config->number_of_philosophers)
		pthread_join(philosophers[i++].thread, NULL);
	return (0);
}
