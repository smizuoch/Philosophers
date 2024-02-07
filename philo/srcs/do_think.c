/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/07 09:07:26 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_think(t_philo *philo)
{
	int	time;

	time = get_time();
	printf("%d %d is thinking\n", time, philo->id);
	return (0);
}
