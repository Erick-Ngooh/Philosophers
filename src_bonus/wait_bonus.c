/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:30:26 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 12:39:37 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	wait_philo(t_philo *philo)
{
	int	status;

	(void)philo;
	while (waitpid(-1, &status, 0) != -1)
	{
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
