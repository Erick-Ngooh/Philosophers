/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:38:45 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 11:41:58 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	exit_philo(t_philo *philo, int exit_value)
{
	sem_close(philo->dead);
	sem_close(philo->fork);
	sem_close(philo->stop);
	sem_close(philo->fork);
	sem_unlink("dead");
	sem_unlink("fork");
	sem_unlink("stop");
	sem_unlink("print");
	if (philo->pid)
		free(philo->pid);
	exit(exit_value);
}
