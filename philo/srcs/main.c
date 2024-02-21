/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 19:36:38 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_mutexdestroy(t_config *config)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&config->mutex);
	while (i < config->number_of_philosophers)
	{
		pthread_mutex_destroy(&config->philos[i].mutex);
		i++;
	}
	i = 0;
	while (i < config->number_of_philosophers)
	{
		pthread_mutex_destroy(&config->forks[i]);
		i++;
	}
	return (0);
}

int	return_error(void)
{
	write(2, "error\n", 7);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_config	config;
	t_philo		*philosophers;

	i = 0;
	memset(&config, 0, sizeof(t_config));
	philosophers = NULL;
	if (argc < 5 || 6 < argc)
		return (return_error());
	if (init_arg(argc, argv, &config))
		return (return_error());
	philosophers = init_philo(&config);
	if (philosophers == NULL)
		return (return_error());
	i = create_thread(&config, philosophers);
	all_mutexdestroy(&config);
	free(philosophers);
	free(config.forks);
	philosophers = NULL;
	config.forks = NULL;
	return (i);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }
