/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:53:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 19:32:11 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static time_t	first_eat_time(t_philo *philo)
{
	int	num;
	int	id;
	int	k;
	int	until_eat;

	num = philo->config->number_of_philosophers;
	if (num == 1)
		return (philo->config->start_time);
	id = philo->id;
	k = num / 2;
	until_eat = philo->config->time_to_eat / k;
	if (until_eat == 0)
		until_eat = 1;
	return (philo->config->start_time + until_eat * ((id * k) % num));
}

static void	*life(t_philo *philo)
{
	int	i;

	i = 0;
	philo->next_eat_time = first_eat_time(philo);
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
	if (pthread_create(&config->thread, NULL,
			(void *)observer, config) != 0)
		return (return_error());
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL,
				(void *)life, &philo[i]) != 0)
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
	pthread_join(config->thread, NULL);
	while (i > 0)
		pthread_join(philo[--i].thread, NULL);
	return (0);
}
