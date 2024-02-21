/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 15:02:10 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	thinking_time(t_philo *philo)
{
	while (philo->next_eat_time > get_time())
		usleep(40);
}

int	do_think(t_philo *philo)
{
	if (print_time_doing(philo, "is thinking"))
		return (1);
	thinking_time(philo);
	return (0);
}
