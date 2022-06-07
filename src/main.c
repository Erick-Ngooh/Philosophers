/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:20:22 by engooh            #+#    #+#             */
/*   Updated: 2022/05/28 19:11:22 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    superviseur(t_data *data)
{
    while (42)
        if (!status_death(data, -1, 0))
            return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!init_philo(&data, ac, av))
		return (0);
    superviseur(&data);
	wait_philo(&data, data.philo, -1);
	destroy_philo(&data, data.philo, -1);
	return (0);
}
