/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:08:19 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 12:48:19 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	status_eat(t_philo *philo)
{
	sem_wait(philo->forks);
	print_philo(philo, "has taken a fork\n");
	sem_wait(philo->forks);
	print_philo(philo, "has taken a fork\n");
	philo->eating = timestamp();
	ft_usleep(philo->tte_std);
	print_philo(philo, "is eating\n");
	philo->eat_n++;
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	status_sleep_and_think(t_philo *philo)
{
	usleep(philo->tte_std);
	print_philo(philo, "is sleeping\n");
	print_philo(philo, "is thinking\n");
}

void	routine(t_philo *philo, int index)
{
	philo->genese = timestamp();
	philo->eating = philo->genese;
	philo->index = index;
	status_eat(philo);
	status_sleep_and_think(philo);
	exit(0);
}
