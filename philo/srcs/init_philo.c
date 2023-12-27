/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:22 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/27 15:07:59 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_config *config, t_philo *philosophers)
{
	int	i;

	i = 0;
	philosophers = (t_philo *)malloc(sizeof(t_philo) * config->number_of_philosophers);
	if (philosophers == NULL)
		return (1);
	while (i < config->number_of_philosophers)
	{
		philosophers[i].config = config;
		
		i ++;
	}
	return (0);
}
