/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:31:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/14 16:33:00 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_sleep(t_philo *philo)
{
	time_t	time;

	time = get_time();
	time = (time - philo->config->start_time);
	printf("%ld %d is sleeping\n", time, philo->id);
	ft_usleep(philo->config->time_to_sleep);
	return (0);
}
