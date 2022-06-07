/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:58:07 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 10:58:09 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	exit_philo(t_philo *philo, int exit_value)
{
	sem_close(philo->print);
	sem_close(philo->forks);
	sem_unlink("/print");
	sem_unlink("/forks");
	if (philo->pid)
		free(philo->pid);
	exit(exit_value);
}
