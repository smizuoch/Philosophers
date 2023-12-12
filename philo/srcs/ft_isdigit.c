/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:43:25 by smizuoch          #+#    #+#             */
/*   Updated: 2023/12/12 15:38:22 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	str_isdigit(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (!(str_isdigit(argv[i])))
			return (1);
		i++;
	}
	return (0);
}
