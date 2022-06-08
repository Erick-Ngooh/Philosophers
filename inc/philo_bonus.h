/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:59:28 by engooh            #+#    #+#             */
/*   Updated: 2022/06/08 13:59:32 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>           /* For O_* constants */
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>        /* For mode constants */
# include <sys/types.h>
# include <sys/time.h>
# include <semaphore.h>
# include "../share/libft/libft.h"

typedef struct s_philo
{
	pthread_t	death;
	sem_t		*stop;
	sem_t		*dead;
	sem_t		*fork;
	sem_t		*print;
	long int	genese;
	long int	time_to_eat;
	long int	time_to_die;
	long int	time_to_sleep;
	long int	last_meal;
	int			*pid;
	int			index;
	int			is_dead;
	int			is_count;
	int			eat_count;
	int			philo_number;
}	t_philo;

int		parse(int ac, char **av);
int		timestamp(void);
int		wait_philo(t_philo *philo, int i);
int		set_philo(t_philo *philo, char **av);
int		create_semaphore(t_philo *philo);
int		kill_process(t_philo *philo, int i);
void	ft_usleep(ssize_t time);
void	open_philo(t_philo *philo, int i);
void	routine(t_philo *philo, int index);
void	print_philo(t_philo *philo, char *str, int check_dead);
void	exit_philo(t_philo *philo, int exit_value);
void	status_eat(t_philo *philo);
void	status_sleep_think(t_philo *philo);
#endif 
