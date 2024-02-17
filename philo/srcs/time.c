/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:16 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/17 12:06:27 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	usec_to_msec(time_t usec)
{
	return (usec / 1000);
}

int	put_message(t_philo *philo, char *action)
{
	int		ret;

	ret = 0;
	pthread_mutex_lock(&philo->config->mutex);
	if (philo->config->observer == 0)
	{
		printf("%ld %d %s\n", get_time(), philo->id, action);
	}
	else
		ret = 1;
	pthread_mutex_unlock(&philo->config->mutex);
	return (ret);
}

time_t	get_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_usleep(int time)
{
	time_t	start;
	time_t	now;

	start = get_time();
	now = start;
	while (now - start < time)
	{
		usleep(40);
		now = get_time();
	}
	return (0);
}
