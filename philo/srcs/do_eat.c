/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:35 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/06 16:02:33 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_eat(t_philo *philo)
{
	int	time;

	time = get_time();
	printf("%d %d is eating\n", time, philo->id);
	ft_usleep(philo->config->time_to_eat);
	philo->config->number_of_times_each_philosopher_must_eat--;
	if (philo->config->number_of_times_each_philosopher_must_eat == 0)
		philo->config->number_of_philosophers--;
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->config->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->config->forks[(philo->id) % philo->config->number_of_philosophers]);
	return (0);
}
