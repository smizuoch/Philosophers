/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:33:52 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/17 14:31:30 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	observer(t_config *config)
{
	int	i;

	while (get_time() < config->start_time)
		usleep(10);
	while (1)
	{
		i = 0;
		while (i < config->number_of_philosophers)
		{
			pthread_mutex_lock(&config->mutex);
			pthread_mutex_lock(&config->philos[i].lock);
			if (get_time() - config->philos[i].last_meal_time > config->time_to_die)
			{
				printf("%ld %d died\n", get_time(), config->philos[i].id);
				config->observer = 1;
				return ;
			}
			pthread_mutex_unlock(&config->philos[i].lock);
			pthread_mutex_unlock(&config->mutex);
			i++;
		}
		if (config->number_of_philosophers == 0)
			return ;
	}
	return ; 
}
