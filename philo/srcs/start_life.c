/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:53:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 12:32:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*life(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->config->start_time > get_time())
		usleep(40);
	pthread_mutex_lock(&philo->config->mutex);
	if (philo->config->observer == 1)
	{
		pthread_mutex_unlock(&philo->config->mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->config->mutex);
	while (1)
	{
		if (do_think(philo) == 1 || do_eat(philo) == 1 || do_sleep(philo) == 1)
			break ;
	}
	return (NULL);
}

int	create_thread(t_config *config, t_philo *philo)
{
	int	i;

	i = 0;
	config->start_time = get_time() + 3000;
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)life, &philo[i]) != 0)
		{
			pthread_mutex_lock(&config->mutex);
			config->observer = 1;
			pthread_mutex_unlock(&config->mutex);
			while (i > 0)
				pthread_join(philo[--i].thread, NULL);
			return (return_error());
		}
		i++;
	}
	while (i > 0)
		pthread_join(philo[--i].thread, NULL);
	return (0);
}