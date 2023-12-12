/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/12 14:55:22 by smizuoch         ###   ########.fr       */
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
	t_arg arg;

	if (argc < 4 || 6 < argc)
		return (return_error());
	if	(init_arg(argc, argv, &arg))
		return (return_error);
	
}