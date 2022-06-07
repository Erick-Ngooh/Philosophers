/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:41 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 00:54:12 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo_bonus.h"

int	parse(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (printf("Error: invalide number argument\n"));
	av = av + 1;
	while (*av)
	{
		if (ft_atoi(*av) == -1)
			return (printf("Error: invalide argument\n"));
		i = -1;
		while (av[0][++i])
			if (!ft_isdigit(av[0][i]))
				return (printf("Error: invalide argument\n"));
		av++;
	}
	return (0);
}

int	set_data(t_philo *philo, char **av)
{
	philo->dead = 1;
	philo->pid = NULL;
	philo->eat_n = 0;
	philo->nbp_std = ft_atoi(av[1]);
	philo->ttd_std = ft_atoi(av[2]);
	philo->tte_std = ft_atoi(av[3]);
	philo->tts_std = ft_atoi(av[4]);
	if (av[5])
	{
		philo->ect_if = 1;
		philo->ect_std = ft_atoi(av[5]);
	}
	else
		philo->ect_if = 0;
	if (philo->nbp_std < 0 || philo->ttd_std < 0 || philo->tte_std < 0
		|| philo->tts_std < 0 || (av[5] && philo->ect_std < 0))
		return (printf("Error: invalid argument can't be negative"));
	if (av[5] && philo->ect_std == 0)
		return (printf("[0] [1] is died\n"));
	return (0);
}

void	create_semaphore_process(t_philo *philo, int i)
{
	philo->print = sem_open("/print", O_CREAT, 0644, 1);
	philo->forks = sem_open("/forks", O_CREAT, 0644, philo->nbp_std);
	if (philo->print == SEM_FAILED || philo->forks == SEM_FAILED)
		exit_philo(philo, 1);
	while (++i < philo->nbp_std)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			exit_philo(philo, 1);
		if (!philo->pid[i])
			routine(philo, i);
		usleep(1000);
	}
}

void	open_philo(t_philo *philo, int ac, char **av)
{
	if (parse(ac, av) || set_data(philo, av))
		exit_philo(philo, 1);
	philo->pid = malloc(sizeof(int) * philo->nbp_std);
	if (!philo->pid)
		exit_philo(philo, 1);
	create_semaphore_process(philo, -1);
}
