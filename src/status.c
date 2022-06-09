/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:15:26 by christellen       #+#    #+#             */
/*   Updated: 2022/06/09 16:20:33 by engooh           ###   ########.fr       */
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

int	status_death(t_data *data, int i, int limit_death)
{
	while (++i < data->nbp_std)
	{
		if ((data->ect_if && data->philo[i].ect >= data->ect_std))
			limit_death++;
		if (data->philo[i].genese
			&& ((timestamp() - data->philo[i].tte >= data->ttd_std)
				|| (data->ect_if && limit_death == data->nbp_std)))
		{
			pthread_mutex_lock(&data->death);
			data->dead = 0;
			pthread_mutex_unlock(&data->death);
			print_philo(data, &data->philo[i], "died\n", 5);
			return (0);
		}
	}
	return (1);
}

void	status_eat_inversion(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	pthread_mutex_lock(&philo->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	philo->tte = timestamp();
	ft_usleep(data->tte_std, data);
	print_philo(data, philo, "is eating\n", 10);
	philo->ect++;
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	status_eat(t_data *data, t_philo *philo)
{
	if (philo->nbp_s != 1 && philo->idx == philo->nbp_s - 1)
		return (status_eat_inversion(data, philo));
	pthread_mutex_lock(&philo->fork);
	print_philo(data, philo, "has taken a fork\n", 17);
	if (philo->next)
	{
		pthread_mutex_lock(&philo->next->fork);
		print_philo(data, philo, "has taken a fork\n", 17);
		philo->tte = timestamp();
		ft_usleep(data->tte_std, data);
		print_philo(data, philo, "is eating\n", 10);
		philo->ect++;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
	else
		pthread_mutex_unlock(&philo->fork);
}

void	status_sleep_think(t_data *data, t_philo *philo)
{
	print_philo(data, philo, "is sleeping\n", 12);
	ft_usleep(data->tts_std, data);
	print_philo(data, philo, "is thinking\n", 12);
}
