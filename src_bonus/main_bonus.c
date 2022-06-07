/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:27:49 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 12:38:47 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	open_philo(&philo, ac, av);
	wait_philo(&philo);
	exit_philo(&philo, 0);
	return (0);
}
