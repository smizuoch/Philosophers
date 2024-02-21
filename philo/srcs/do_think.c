/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:28:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 11:50:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	do_think(t_philo *philo)
{
	if (print_time_doing(philo, "is thinking\n"))
		return (1);
	return (0);
}
