/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:53:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/10 13:58:49 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosopher_function(t_philo *philo)
{
	while (get_time() < philo->config->start_time)
		usleep(10);
	philo->last_meal_time = get_time();
	if (philo->id % 2 == 0)
	{
		usleep(100);
	}
	while (1)
	{
		if (philo->config->observer == 1)
			return (0);
		take_fork(philo);
		if (philo->config->observer == 1)
			return (0);
		do_eat(philo);
		if (philo->config->observer == 1)
			return (0);
		do_sleep(philo);
		if (philo->config->observer == 1)
			return (0);
		do_think(philo);
	}
	return (0);
}

int	start_life(t_config *config, t_philo *philosophers)
{
	int	i;
	pthread_t observer_thread;

	i = 0;
	config->start_time = get_time()
		+ config->number_of_philosophers * 50;
	if (pthread_create(&observer_thread, NULL, \
			(void *)observer, config) != 0)
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
				(void *)philosopher_function, &philosophers[i]) != 0)
			return (return_error());
		i ++;
	}
	i = 0;
	while (i < config->number_of_philosophers)
		pthread_join(philosophers[i++].thread, NULL);
	pthread_join(observer_thread, NULL);
	return (0);
}
