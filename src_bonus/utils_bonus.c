/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:58:23 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 01:08:36 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(ssize_t time)
{
	ssize_t	res;
	double	wt;

	wt = time / 10;
	res = timestamp() + time;
	while (timestamp() < res)
	{
		if (time > 1000)
			usleep(100);
		else
			usleep(wt);
	}
}

void	print_philo(t_philo *philo, char *str, int check_death)
{	
	sem_wait(philo->dead);
	if (check_death && !philo->is_dead)
		exit(0);
	sem_post(philo->dead);
	sem_wait(philo->print);
	printf("{%ld} {%d} %s", timestamp() - philo->genese, philo->index, str);
	sem_post(philo->print);
}
