/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/12 15:40:50 by smizuoch         ###   ########.fr       */
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

	if (argc < 5 || 6 < argc)
		return (return_error());
	if (init_arg(argc, argv, &arg))
		return (return_error());
	printf("%d\n", arg.number_of_philosophers);
}
