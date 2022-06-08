/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:12 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 12:40:52 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	routine(t_philo *philo, int index)
{
	philo->index = index;
	philo->genese = timestamp();
	print_philo(philo, "ok\n", 1);
	sem_post(philo->stop);
}
