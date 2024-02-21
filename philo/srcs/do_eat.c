/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:35 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 15:54:28 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->config->forks[philo->id]);
	if (print_time_doing(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->config->forks[philo->id]);
		return (1);
	}
	if (philo->config->number_of_philosophers == 1)
		return (1);
	pthread_mutex_lock(&philo->config->forks[(philo->id + 1)
		% philo->config->number_of_philosophers]);
	if (print_time_doing(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->config->forks[philo->id]);
		pthread_mutex_unlock(&philo->config->forks[(philo->id + 1)
			% philo->config->number_of_philosophers]);
		return (1);
	}
	return (0);
}

static void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->config->forks[philo->id]);
	pthread_mutex_unlock(&philo->config->forks[(philo->id + 1)
		% philo->config->number_of_philosophers]);
}

static time_t	predicts_time_to_eat(t_philo *philo, time_t last_eat)
{
	int		num;
	int		k;
	double	adj_time;

	num = philo->config->number_of_philosophers;
	k = num / 2;
	adj_time = (double)num * philo->config->time_to_eat / k;
	if (adj_time > (time_t)adj_time)
		adj_time = (time_t)adj_time + 1;
	if (adj_time < philo->config->time_to_eat + philo->config->time_to_sleep)
		adj_time = philo->config->time_to_eat + philo->config->time_to_sleep;
	return (last_eat + (time_t)adj_time);
}

int	do_eat(t_philo *philo)
{
	time_t	now;

	if (take_fork(philo))
		return (1);
	now = get_time();
	if (print_time_doing(philo, "is eating"))
	{
		put_fork(philo);
		return (1);
	}
	pthread_mutex_lock(&philo->mutex);
	philo->last_eat_time = now;
	pthread_mutex_unlock(&philo->mutex);
	ft_usleep(philo->config->time_to_eat);
	philo->next_eat_time = predicts_time_to_eat(philo, now);
	put_fork(philo);
	pthread_mutex_lock(&philo->mutex);
	philo->eat_count ++;
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}
