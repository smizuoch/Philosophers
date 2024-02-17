/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:35 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/17 14:30:40 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_eat(t_philo *philo)
{
	time_t	time;

	time = get_time();
	time = (time - philo->config->start_time);
	printf("%ld %d is eating\n", time, philo->id);
	ft_usleep(philo->config->time_to_eat);
	philo->config->number_of_times_each_philosopher_must_eat--;
	if (philo->config->number_of_times_each_philosopher_must_eat == 0)
		philo->config->number_of_philosophers--;
	philo->eat_count++;
	pthread_mutex_lock(&philo->lock);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->config->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->config->forks[(philo->id)
		% philo->config->number_of_philosophers]);
	return (0);
}
