/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:17:07 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 15:45:59 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	pthread_t		thrid;
	struct s_data	*data;
	struct s_philo	*next;
	pthread_mutex_t	fork;	
	int				idx;
	int				ect;
	int				nbp_s;
	int				acess;
	long int		tte;
	long int		ttd_s;
	long int		tte_s;
	long int		tts_s;
	long int		ect_s;
	long int		genese;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	print;
	pthread_mutex_t	time;
	pthread_mutex_t	death;
	t_philo			*philo;
	int				dead;
	int				ect_if;
	int				nbp_std;
	long int		genese;
	long int		ttd_std;
	long int		tte_std;
	long int		tts_std;
	long int		ect_std;
}	t_data;

int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
int			parse(int ac, char **av);
int			set_data(t_data *data, char **av);
int			init_philo(t_data *data, int ac, char **av);
int			wait_philo(t_data *data, t_philo *philo, int i);
int			print_philo(t_data *data, t_philo *philo, char *str, int size);
int			check_death(t_data *data, int r);
int			status_death(t_data *data, int i, int limit_death);
long int	timestamp(void);
void		*routine(void *arg);
void		ft_usleep(ssize_t time, t_data *data);
void		destroy_philo(t_data *data, t_philo *philo, int i);
void		status_eat(t_data *data, t_philo *philo);
void		status_sleep_think(t_data *data, t_philo *philo);
#endif 
