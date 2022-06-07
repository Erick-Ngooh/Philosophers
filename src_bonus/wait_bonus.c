/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:30:26 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 00:44:23 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	wait_philo(t_philo *philo, int i)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	i = -1;
	while (++i < philo->nbp_std)
		kill(philo->pid[i], SIGTERM);
	return (1);
}
