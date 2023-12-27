/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:22 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/27 17:27:38 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(t_config *config)
{
	int		i;
	t_philo	*philosophers;

	i = 0;
	philosophers = (t_philo *)malloc
		(sizeof(t_philo) * config->number_of_philosophers);
	if (philosophers == NULL)
		return (NULL);
	memset(philosophers, 0, sizeof(t_philo));
	while (i < config->number_of_philosophers)
	{
		philosophers[i].config = config;
		philosophers[i].id = i + 1;
		i ++;
	}
	config->philos = philosophers;
	return (philosophers);
}
