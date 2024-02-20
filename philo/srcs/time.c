/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:16 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/20 10:08:09 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_time_doing(t_philo *philo, char *doing)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->config->mutex);
	if (philo->config->observer == 0)
	{
		printf("%ld %d %s\n", get_time() - philo->config->start_time,
			philo->id, doing);
	}
	else
		i = 1;
	pthread_mutex_unlock(&philo->config->mutex);
	return (i);
}

time_t	get_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_usleep(time_t time)
{
	time_t	start;
	time_t	end;

	start = get_time();
	end = start + time;
	while (get_time() < end)
		usleep(40);
}
