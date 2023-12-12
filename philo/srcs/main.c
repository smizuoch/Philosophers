/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/12 15:46:02 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	return_error(void)
{
	write(2, "error in argument\n", 19);
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	arg.number_of_times_each_philosopher_must_eat = -1;
	if (argc < 5 || 6 < argc)
		return (return_error());
	if (init_arg(argc, argv, &arg))
		return (return_error());
	printf("%d\n%d\n%d\n%d\n%d\n", arg.number_of_philosophers, arg.time_to_die, arg.time_to_eat, arg.time_to_sleep, arg.number_of_times_each_philosopher_must_eat);
}
