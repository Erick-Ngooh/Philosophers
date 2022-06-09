/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:08:40 by engooh            #+#    #+#             */
/*   Updated: 2022/06/09 17:57:46 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	m;

	m = n;
	if (m < 0)
	{
		m = -m;
		ft_putchar_fd('-', fd);
	}
	if (m > 9)
	{
		ft_putnbr_fd((m / 10), fd);
		ft_putchar_fd((m % 10) + '0', fd);
	}
	if (m >= 0 && m <= 9)
		ft_putchar_fd(m + '0', fd);
}

int	print_philo(t_data *data, t_philo *philo, char *str, int size)
{
	pthread_mutex_lock(&data->print);
	if (!check_death(data, 1) && size != 5)
	{
		pthread_mutex_unlock(&data->print);
		return (0);
	}
	write(1, "[", 1);
	ft_putnbr_fd(timestamp() - philo->genese, 1);
	write(1, "]", 1);
	write(1, " ", 1);
	write(1, "[", 1);
	ft_putnbr_fd(philo->idx + 1, 1);
	write(1, "]", 1);
	write(1, " ", 1);
	write(1, str, size);
	pthread_mutex_unlock(&data->print);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	n;

	n = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
		{
			while (ft_isdigit(*nptr))
			{
				n = (n * 10) - (*nptr++ - '0');
				if (n < INT_MIN)
					return (0);
			}
		}
	}
	while (ft_isdigit(*nptr))
	{
		n = (n * 10) + (*nptr++ - '0');
		if (n > INT_MAX)
			return (-1);
	}
	return (n);
}
