/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:19:06 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 11:20:53 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	parse(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (printf("Error: invalide number argument\n"));
	av = av + 1;
	while (*av)
	{
		if (ft_atoi(*av) == -1)
			return (printf("Error: invalide argument\n"));
		i = -1;
		while (av[0][++i])
			if (!ft_isdigit(av[0][i]))
				return (printf("Error: invalide argument\n"));
		av++;
	}
	return (0);
}
