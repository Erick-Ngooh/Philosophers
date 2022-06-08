/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:11:34 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 00:05:16 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (parse(ac, av) || set_philo(&philo, av))
		return (1);
	if (!create_semaphore(&philo))
		return (1);
	open_philo(&philo, -1);
	kill_process(&philo, -1);
	exit_philo(&philo, 0);
	return (0);
}
