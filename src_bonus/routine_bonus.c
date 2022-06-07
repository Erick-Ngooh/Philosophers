/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:08:19 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 00:59:13 by engooh           ###   ########.fr       */
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
	print_philo(philo, "is sleeping\n");
	ft_usleep(philo->tts_std);
	print_philo(philo, "is thinking\n");
}

void	*status_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (42)
	{
		if (timestamp() - philo->eating >= philo->tts_std)
		{
			print_philo(philo, "is died\n");
			exit(1);
		}
	}
	return (NULL);
}

void	routine(t_philo *philo, int index)
{
	t_philo	tmp;

	if (index % 2 == 1)
		usleep(philo->tte_std * 1000);
	tmp.nbp_std = philo->nbp_std;
	tmp.tte_std = philo->tte_std;
	tmp.tts_std = philo->tts_std;
	tmp.ttd_std = philo->ttd_std;
	tmp.death = philo->death;
	tmp.genese = timestamp();
	tmp.eating = tmp.genese;
	tmp.print = philo->print;
	tmp.forks = philo->forks;
	tmp.index = index;
	if (pthread_create(&philo->death, NULL, status_death, &tmp) < 0)
		exit(1);
	status_eat(&tmp);
	status_sleep_and_think(&tmp);
	if (pthread_join(tmp.death, NULL))
		exit(1);
	exit(0);
}
