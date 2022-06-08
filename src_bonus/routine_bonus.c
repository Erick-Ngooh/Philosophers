/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:12 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 01:44:26 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	*thread_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->genese)
		usleep(1);
	while (42)
	{
		if (timestamp() - philo->last_meal >= philo->time_to_die)
		{
			sem_wait(philo->dead);
			philo->is_dead = 0;
			sem_post(philo->dead);
			print_philo(philo, "is died\n", 0);
			break ;
		}
	}
	return (NULL);
}

void	routine(t_philo *philo, int index)
{
	if (pthread_create(&philo->death, NULL, thread_check_death, philo))
		exit(1);
	if (index % 2 == 1)
		usleep(philo->time_to_die * 1000);
	philo->index = index;
	philo->genese = timestamp();
	philo->last_meal = philo->genese;
	status_eat(philo);
	status_sleep_think(philo);
	if (pthread_join(philo->death, NULL))
		exit(1);
	exit(0);
}
