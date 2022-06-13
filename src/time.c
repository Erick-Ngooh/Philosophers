/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:01 by engooh            #+#    #+#             */
/*   Updated: 2022/06/13 22:58:59 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(ssize_t time, t_data *data)
{
	long int	current;
	ssize_t		res;

	res = timestamp();
	while (1)
	{
		current = timestamp() - res;
		if (current >= time)
			break ;
		if (time - current >= 1000)
			usleep(100);
		else
			usleep((time - current) / 10);
		if (!check_death(data, 1))
			return ;
	}
}
