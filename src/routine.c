/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:20:59 by christellen       #+#    #+#             */
/*   Updated: 2022/06/09 16:12:00 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->idx % 2 == 0)
		usleep(100);
	philo->genese = timestamp();
	philo->tte = philo->genese;
	while (check_death(data, 1))
	{
		status_eat(data, philo);
		status_sleep_think(data, philo);
	}
	return (NULL);
}
