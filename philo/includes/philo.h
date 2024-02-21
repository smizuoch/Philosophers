/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:55:38 by smizuoch          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:02 by smizuoch         ###   ########.fr       */
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
# include <sys/time.h>
# include<stdbool.h>

typedef struct s_config	t_config;

typedef struct s_philo
{
	int				id;
	t_config		*config;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	time_t			next_eat_time;
	int				is_dead;
	int				eat_count;
	time_t			last_eat_time;
}	t_philo;

struct s_config
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	pthread_t		thread;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philos;
	time_t			start_time;
	int				observer;
};

//init
int		philo_atoi(const char *str);
int		ft_isdigit(int c);
int		str_isdigit(char *str);
int		init_arg(int argc, char **argv, t_config *config);
int		check_arg(int argc, char **argv);
t_philo	*init_philo(t_config *config);
int		return_error(void);

//time
time_t	get_time(void);
void	ft_usleep(time_t time);
int		print_time_doing(t_philo *philo, char *doing);

//main
int		create_thread(t_config *config, t_philo *philo);
int		do_eat(t_philo *philo);
int		do_sleep(t_philo *philo);
int		do_think(t_philo *philo);
void	*observer(t_config *config);

#endif
