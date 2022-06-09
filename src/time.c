/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:01 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 15:41:21 by engooh           ###   ########.fr       */
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
	ssize_t		res;
	double		wt;

	wt = time / 10;
	res = timestamp() + time;
	while (timestamp() < res)
	{
		if (time > 1000)
			usleep(100);
		else
			usleep(wt);
		if (!check_death(data, 1))
			return ;
	}
}
