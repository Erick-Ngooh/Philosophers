/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:20:59 by christellen       #+#    #+#             */
/*   Updated: 2022/06/17 09:35:32 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&philo->mutex_genese);
	philo->genese = timestamp();
	pthread_mutex_lock(&philo->check_meal);
	philo->tte = philo->genese;
	pthread_mutex_unlock(&philo->mutex_genese);
	pthread_mutex_unlock(&philo->check_meal);
	if (philo->idx % 2 == 0)
		ft_usleep(philo->tte_s / 10, data);
	while (check_death(data, 1))
	{
		status_eat(data, philo);
		status_sleep_think(data, philo);
	}
	return (NULL);
}
