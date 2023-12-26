/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:55:38 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/26 14:54:31 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_config t_config;

typedef struct s_philo
{
	int			id;
	t_config	*config;
	pthread_mutex_t	lock;
	pthread_t	thread;
}	t_philo;

struct s_config
{
	pthread_mutex_t	*forks;
	
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_philo	*philos;
};

int	philo_atoi(const char *str);
int	ft_isdigit(int c);
int	str_isdigit(char *str);
int	init_arg(int argc, char **argv, t_config *config);
int	check_arg(int argc, char **argv);

#endif
