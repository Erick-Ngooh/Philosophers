/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:59:28 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 11:24:35 by engooh           ###   ########.fr       */
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
	sem_t		*forks;
	sem_t		*print;
	long int	index;
	long int	eat_n;
	long int	genese;
	long int	eating;
	long int	tte_std;
	long int	tts_std;	
	long int	ttd_std;
	long int	nbp_std;
	long int	ect_std;
	int			*pid;
	int			dead;
	int			ect_if;
}	t_philo;

int		timestamp(void);
void	ft_usleep(ssize_t time);
void	routine(t_philo *philo, int index);
void	print_philo(t_philo *philo, char *str);

void	exit_philo(t_philo *philo, int exit_value);
void	open_philo(t_philo *philo, int ac, char **av);
#endif 
