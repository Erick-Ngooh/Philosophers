/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:17:07 by engooh            #+#    #+#             */
/*   Updated: 2022/05/29 19:33:17 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*	"../src" */
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "../share/libft/libft.h"

struct	s_data;

typedef struct s_philo
{
	int					idx;
	int					ect;
	long int			tte;
	int					nbp_s;
	long int			ttd_s;
	long int			tte_s;
	long int			tts_s;
	long int			ect_s;
    int                 acess;
	long int			genese;
	struct s_data		*data;
    struct s_philo      *next;
	pthread_mutex_t		fork;	
	pthread_t			thrid;
}	t_philo;

typedef struct s_data
{
	int					dead;
	long int			genese;
    int                 ect_if;
	int					nbp_std;
	long int			ttd_std;
	long int			tte_std;
	long int			tts_std;
	long int			ect_std;
	t_philo				*philo;
	pthread_mutex_t		print;
	pthread_mutex_t		time;
	pthread_mutex_t		death;
}	t_data;

long int	timestamp(void);
void		*routine(void *arg);
int			parse(int ac, char **av);
int			set_data(t_data *data, char **av);
void		ft_usleep(ssize_t time, t_data *data);
int			init_philo(t_data *data, int ac, char **av);
int			wait_philo(t_data *data, t_philo *philo, int i);
void		destroy_philo(t_data *data, t_philo *philo, int i);
int			print_philo(t_data *data, t_philo *philo, char *str, int size);
int         check_death(t_data *data, int r);
void		status_eat(t_data *data, t_philo *philo);
void		status_sleep_think(t_data *data, t_philo *philo);
int         status_death(t_data *data, int i, int limit_death);
#endif 
