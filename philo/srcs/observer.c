/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:33:52 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/06 16:05:11 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	observer(t_config *config)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < config->number_of_philosophers)
		{
			pthread_mutex_lock(&config->mutex);
			if (get_time() - config->philos[i].last_eat > config->time_to_die)
			{
				printf("%d %d died\n", get_time(), config->philos[i].id);
				return (1);
			}
			pthread_mutex_unlock(&config->mutex);
			i++;
		}
		if (config->number_of_philosophers == 0)
			return (0);
	}
	return (0); 
}
