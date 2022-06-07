/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:20:59 by christellen       #+#    #+#             */
/*   Updated: 2022/05/29 19:46:16 by christellen      ###   ########.fr       */
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

int	print_philo(t_data *data, t_philo *philo, char *str, int size)
{
    pthread_mutex_lock(&data->print);
	if (!check_death(data, 1) && size != 5)
    {
        pthread_mutex_unlock(&data->print);
		return (0);
    }
	write(1, "[", 1);
	ft_putnbr_fd(timestamp() - philo->genese, 1);
	write(1, "]", 1);
	write(1, " ", 1);
	write(1, "[", 1);
	ft_putnbr_fd(philo->idx, 1);
	write(1, "]", 1);
	write(1, " ", 1);
	write(1, str, size);
    pthread_mutex_unlock(&data->print);
	return (0);
}

void	*routine(void *arg)
{
	t_data	*data; 
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->idx % 2 == 0)
	{
		usleep(100);
		philo->genese = timestamp();
	}
	else
		philo->genese = timestamp();
    philo->tte = philo->genese;
    while (check_death(data, 1))
    {
	    status_eat(data, philo);
	    status_sleep_think(data, philo);
    }
	return (NULL);
}
