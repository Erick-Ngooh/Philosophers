/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:38:34 by christellen       #+#    #+#             */
/*   Updated: 2022/06/16 01:29:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	destroy_philo(t_data *data, t_philo *philo, int i)
{
	if (!data)
		return ;
	while (++i < data->nbp_std)
	{
		pthread_mutex_destroy(&philo[i].fork);
		pthread_mutex_destroy(&philo[i].mutex_ect);
		pthread_mutex_destroy(&philo[i].check_meal);
		pthread_mutex_destroy(&philo[i].mutex_genese);
	}
	free(philo);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->print);
}
