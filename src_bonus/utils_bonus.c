/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:10:05 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 11:35:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep1(ssize_t time, t_philo *philo)
{
	ssize_t	res;
	double	wt;

	(void)philo;
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

void	print_philo(t_philo *philo, char *str)
{
	sem_wait(philo->print);
	printf("{%ld} {%ld} %s", timestamp() - philo->genese, philo->index, str);
	sem_post(philo->print);
}
