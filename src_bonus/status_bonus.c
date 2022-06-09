/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:45:46 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 17:10:30 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	status_eat(t_philo *philo)
{
	sem_wait(philo->fork);
	print_philo(philo, "has taken fork\n", 1);
	if (philo->philo_number != 1)
	{
		sem_wait(philo->fork);
		print_philo(philo, "has taken fork\n", 1);
		philo->eat_count--;
		philo->last_meal = timestamp();
		ft_usleep(philo->time_to_eat);
		print_philo(philo, "is eating\n", 1);
		sem_post(philo->fork);
	}
	sem_post(philo->fork);
}

void	status_sleep_think(t_philo *philo)
{
	print_philo(philo, "is sleeping\n", 1);
	ft_usleep(philo->time_to_sleep);
	print_philo(philo, "is thinking\n", 1);
}
