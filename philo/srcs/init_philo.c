/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:22 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/14 13:52:44 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_forks(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->number_of_philosophers)
	{
		if (pthread_mutex_init(&config->forks[i], NULL) != 0)
			return (free(config->forks), 1);
		i ++;
	}
	return (0);
}

t_philo	*init_philo(t_config *config)
{
	int		i;
	t_philo	*philosophers;

	i = 0;
	philosophers = (t_philo *)malloc
		(sizeof(t_philo) * config->number_of_philosophers);
	if (philosophers == NULL)
		return (NULL);
	config->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * config->number_of_philosophers);
	if (config->forks == NULL)
		return (free(philosophers), NULL);
	memset(philosophers, 0, sizeof(t_philo));
	memset(config->forks, 0, sizeof(pthread_mutex_t));
	while (i < config->number_of_philosophers)
	{
		philosophers[i].config = config;
		philosophers[i].id = i + 1;
		i ++;
	}
	if (init_forks(config))
		return (free(philosophers), NULL);
	config->philos = philosophers;
	return (philosophers);
}
