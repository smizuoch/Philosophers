/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:26:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/10 13:53:15 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/philo.h"

// int	take_fork(t_philo *philo)
// {
// 	time_t	time;
	
// 	time = get_time();
// 	pthread_mutex_lock(&philo->config->forks[philo->id - 1]);
// 	printf("%ld %d has taken a fork\n", time, philo->id);
// 	pthread_mutex_lock(&philo->config->forks[(philo->id) % philo->config->number_of_philosophers]);
// 	printf("%ld %d has taken a fork\n", time, philo->id);
// 	return (0);
// }

#include "../includes/philo.h"

int	take_fork(t_philo *philo)
{
	time_t	time;
	
	time = get_time();
	if (philo->id % 2 == 0) {
		pthread_mutex_lock(&philo->config->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->config->forks[(philo->id) % philo->config->number_of_philosophers]);
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has taken a fork\n", time, philo->id);
	} else {
		pthread_mutex_lock(&philo->config->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->config->forks[(philo->id) % philo->config->number_of_philosophers]);
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has taken a fork\n", time, philo->id);
	}
	return (0);
}
