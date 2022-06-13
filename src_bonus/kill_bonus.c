/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:52:55 by engooh            #+#    #+#             */
/*   Updated: 2022/06/13 21:10:28 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	kill_process(t_philo *philo, int i)
{
	int	status;

	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	i = -1;
	while (++i < philo->philo_number)
	{
		kill(philo->pid[i], SIGKILL);
		usleep(100);
	}
	return (1);
}
