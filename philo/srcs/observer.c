/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:33:52 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 21:00:47 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*observer(t_config *config)
{
	int		i;
	bool	is_dead[200];

	i = 0;
	memset(is_dead, 0, sizeof(is_dead));
	while (config->start_time > get_time())
		usleep(40);
	while (1)
	{
		i = 0;
		while (i < config->number_of_philosophers)
		{
			pthread_mutex_lock(&config->philos[i].mutex);
			if (config->philos[i].last_eat_time
				+ config->time_to_die < get_time())
			{
				pthread_mutex_lock(&config->mutex);
				printf("%ld %d died\n", get_time() - config->start_time, i + 1);
				config->observer = 1;
				pthread_mutex_unlock(&config->mutex);
				pthread_mutex_unlock(&config->philos[i].mutex);
				return (NULL);
			}
			else if (config->number_of_times_each_philosopher_must_eat != -1
				&& config->philos[i].eat_count
				>= config->number_of_times_each_philosopher_must_eat)
				is_dead[i] = 1;
			pthread_mutex_unlock(&config->philos[i].mutex);
			i++;
		}
		i = 0;
		while (i < config->number_of_philosophers)
		{
			if (is_dead[i] == 0)
				break ;
			i++;
		}
		if (i == config->number_of_philosophers)
		{
			pthread_mutex_lock(&config->mutex);
			config->observer = 1;
			pthread_mutex_unlock(&config->mutex);
			break ;
		}
	}
	return (NULL);
}
