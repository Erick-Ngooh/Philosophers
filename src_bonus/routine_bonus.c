/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:12 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 13:59:01 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	routine(t_philo *philo, int index)
{
	philo->index = index;
	philo->genese = timestamp();
	status_eat(philo);
	status_sleep_think(philo);
	sem_post(philo->stop);
}
