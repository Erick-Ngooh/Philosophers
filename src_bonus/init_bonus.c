/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:21:52 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 22:33:33 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	set_philo(t_philo *philo, char **av)
{
	philo->genese = 0;
	philo->eat_count = 0;
	philo->philo_number = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		philo->is_count = 1;
		philo->eat_count = ft_atoi(av[5]);
	}
	else
		philo->is_count = 0;
	if (philo->philo_number < 0 || philo->time_to_die < 0
		|| philo->time_to_eat < 0 || philo->time_to_sleep < 0
		|| (av[5] && philo->eat_count < 0))
		return (printf("Error: invalid argument can't be negative"));
	if (av[5] && philo->eat_count == 0)
		return (printf("[0] [1] is died\n"));
	philo->pid = malloc(sizeof(int) * philo->philo_number);
	if (!philo->pid)
		return (1);
	return (0);
}

int	create_semaphore(t_philo *philo)
{
	philo->dead = sem_open("/dead", O_CREAT, 0644, 1);
	philo->print = sem_open("/print", O_CREAT, 0644, 1);
	philo->stop = sem_open("/stop", O_CREAT, 0644, 1);
	philo->fork = sem_open("/fork", O_CREAT, 0644, philo->philo_number);
	if (philo->dead == SEM_FAILED || philo->fork == SEM_FAILED
		|| philo->stop == SEM_FAILED || philo->print == SEM_FAILED)
		return (0);
	return (1);
}
