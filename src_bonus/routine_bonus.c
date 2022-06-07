/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:08:19 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 11:35:43 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

void	routine(t_philo *philo, int index)
{
	philo->genese = timestamp();
	philo->eating = philo->genese;
	philo->index = index;
	print_philo(philo, "ok\n");
	exit(0);
}
