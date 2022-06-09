/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:51:03 by engooh            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/09 03:00:16 by engooh           ###   ########.fr       */
=======
/*   Updated: 2022/06/08 23:59:01 by engooh           ###   ########.fr       */
>>>>>>> parent of 61440fa (philo_bonus: c'est la fin, encore un peu de force avant la boucle)
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	open_philo(t_philo *philo, int i)
{
	while (++i < philo->philo_number)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			exit_philo(philo, 1);
		if (!philo->pid[i])
			routine(philo, i);
<<<<<<< HEAD
		usleep(1000);
=======
		usleep(100);
>>>>>>> parent of 61440fa (philo_bonus: c'est la fin, encore un peu de force avant la boucle)
	}
}
