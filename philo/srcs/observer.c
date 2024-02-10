/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:33:52 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/10 14:00:33 by smizuoch         ###   ########.fr       */
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
			if (get_time() - config->philos[i].last_meal_time > config->time_to_die)
			{
				printf("%ld %d died\n", get_time(), config->philos[i].id);
				config->observer = 1;
				return ;
			}
			pthread_mutex_unlock(&config->mutex);
			i++;
		}
		if (config->number_of_philosophers == 0)
			return ;
	}
	return ; 
}
