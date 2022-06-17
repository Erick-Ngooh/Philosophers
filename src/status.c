/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:22:48 by engooh            #+#    #+#             */
/*   Updated: 2022/06/17 10:25:07 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	check_death(t_data *data, int r)
{
	pthread_mutex_lock(&data->death);
	if (!data->dead)
		r = 0;
	pthread_mutex_unlock(&data->death);
	return (r);
}

void	status_sleep_think(t_data *data, t_philo *philo)
{
	if (philo->next)
	{
		print_philo(data, philo, "is sleeping\n", 12);
		ft_usleep(philo->tts_s, data);
		print_philo(data, philo, "is thinking\n", 12);
	}
}

void	status_eat_inversion(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	pthread_mutex_lock(&philo->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	pthread_mutex_lock(&philo->check_meal);
	philo->tte = timestamp();
	pthread_mutex_unlock(&philo->check_meal);
	print_philo(data, philo, "is eating\n", 10);
	ft_usleep(philo->tte_s, data);
	pthread_mutex_lock(&philo->mutex_ect);
	philo->ect--;
	pthread_mutex_unlock(&philo->mutex_ect);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	status_eat(t_data *data, t_philo *philo)
{
	if (philo->next && philo->idx == philo->nbp_s - 1)
		return (status_eat_inversion(data, philo));
	pthread_mutex_lock(&philo->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	if (!philo->next)
	{
		ft_usleep(philo->ttd_s, philo->data);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	pthread_mutex_lock(&philo->check_meal);
	philo->tte = timestamp();
	pthread_mutex_unlock(&philo->check_meal);
	print_philo(data, philo, "is eating\n", 10);
	ft_usleep(philo->tte_s, data);
	pthread_mutex_lock(&philo->mutex_ect);
	philo->ect--;
	pthread_mutex_unlock(&philo->mutex_ect);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

int	status_death(t_data *data, int i, int limit_death)
{
	long int	tte;
	long int	time_die;

	while (++i < data->nbp_std)
	{
		pthread_mutex_lock(&data->philo[i].mutex_ect);
		if (data->ect_if && !data->philo[i].ect)
			limit_death++;
		pthread_mutex_unlock(&data->philo[i].mutex_ect);
		pthread_mutex_lock(&data->philo[i].check_meal);
		tte = data->philo[i].tte;
		time_die = timestamp() - tte;
		pthread_mutex_unlock(&data->philo[i].check_meal);
		if (tte && ((time_die > data->ttd_std)
				|| (data->ect_if && limit_death == data->nbp_std)))
		{
			print_philo(data, &data->philo[i], "died\n", 5);
			pthread_mutex_lock(&data->death);
			data->dead = 0;
			pthread_mutex_unlock(&data->death);
			return (0);
		}
	}
	return (1);
}
