/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_thought.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/01/17 11:58:59 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_thought(t_philo *philo)
{
	int	time;

	time = get_time();
	printf("%d %d is thinking\n", time, philo->id);
	return (0);
}
