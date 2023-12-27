/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/27 15:31:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	return_error(void)
{
	write(2, "error\n", 7);
	return (1);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_philo		*philosophers;

	philosophers = NULL;
	if (argc < 5 || 6 < argc)
		return (return_error());
	if (init_arg(argc, argv, &config))
		return (return_error());
	if (init_philo(&config, philosophers))
		return (return_error());
	
	return (0);
}
