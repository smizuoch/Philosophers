/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:53:31 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/29 12:17:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosopher_function(t_philo *philosophers)
{
	while (1)
	{
		philosophers->id = 1;
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
	i = 0;
	while (i < config->number_of_philosophers)
		pthread_join(philosophers[i++].thread, NULL);
	return (0);
}
