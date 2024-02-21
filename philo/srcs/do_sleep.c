/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:31:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 12:32:28 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_sleep(t_philo *philo)
{
	if (print_time_doing(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->config->time_to_sleep);
	return (0);
}
