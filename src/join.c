/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:05:07 by christellen       #+#    #+#             */
/*   Updated: 2022/05/29 19:46:41 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	wait_philo(t_data *data, t_philo *philo, int i)
{
	while (++i < data->nbp_std)
		if (pthread_join(philo[i].thrid, NULL))
			return (printf("Error: thread %d can't be join\n", philo[i].idx));
	return (0);
}
