/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:16 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/29 15:17:20 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (return_error());
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(40);
	return (0);
}
