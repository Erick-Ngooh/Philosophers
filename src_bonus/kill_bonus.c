/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:52:55 by engooh            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/09 03:06:32 by engooh           ###   ########.fr       */
=======
/*   Updated: 2022/06/08 23:16:16 by engooh           ###   ########.fr       */
>>>>>>> parent of 61440fa (philo_bonus: c'est la fin, encore un peu de force avant la boucle)
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	kill_process(t_philo *philo, int i)
{
	int	status;

	waitpid(-1, &status, 0);
	i = -1;
	while (++i < philo->philo_number)
		kill(philo->pid[i], SIGKILL);
	return (1);
}
