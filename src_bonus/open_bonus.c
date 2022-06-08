/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:51:03 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 22:24:43 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	open_philo(t_philo *philo, int i)
{
	while (++i < philo->philo_number)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			exit_philo(philo, 1);
		if (!philo->pid[i])
		{
			routine(philo, i);
			exit(0);
		}
	}
}
