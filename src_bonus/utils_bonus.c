/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:58:23 by engooh            #+#    #+#             */
/*   Updated: 2022/06/13 21:08:06 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

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
	if (check_death)
		sem_post(philo->print);
	else
		exit(0);
}

int	ft_atoi(const char *nptr)
{
	long int	n;

	n = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
		{
			while (ft_isdigit(*nptr))
			{
				n = (n * 10) - (*nptr++ - '0');
				if (n < INT_MIN)
					return (0);
			}
		}
	}
	while (ft_isdigit(*nptr))
	{
		n = (n * 10) + (*nptr++ - '0');
		if (n > INT_MAX)
			return (-1);
	}
	return (n);
}
