/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:56:23 by engooh            #+#    #+#             */
/*   Updated: 2021/11/29 21:06:53 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
