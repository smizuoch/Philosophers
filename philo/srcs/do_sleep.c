/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:31:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/01/17 11:56:40 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_sleep(t_philo *philo)
{
	int	time;

	time = get_time();
	printf("%d %d is sleeping\n", time, philo->id);
	ft_usleep(philo->config->time_to_sleep);
	return (0);
}
