/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/26 13:38:45 by smizuoch         ###   ########.fr       */
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
	int			i;
	t_config	config;
	pthread_t	*threads;

	i = 0;
	config.number_of_times_each_philosopher_must_eat = -1;
	if (argc < 5 || 6 < argc)
		return (return_error());
	if (init_arg(argc, argv, &config))
		return (return_error());
	threads = malloc(sizeof(pthread_t) * config.number_of_philosophers);
	if (!threads)
		return (return_error());
	free(threads);
	return (0);
}
