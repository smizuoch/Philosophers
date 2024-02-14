/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/14 16:32:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_think(t_philo *philo)
{
	time_t	time;

	time = get_time();
	time = (time - philo->config->start_time);
	printf("%ld %d is thinking\n", time, philo->id);
	return (0);
}
