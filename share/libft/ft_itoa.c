/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:17 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 18:56:37 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_intlen(long n, long l)
{
	if (n == 0)
		return (1);
	if (n < 0 && ++l)
		n *= -1;
	while (n && ++l)
		n /= 10;
	return (l);
}

char	*ft_itoa(int n)
{
	long			l;
	unsigned int	k;
	char			*p;

	k = n;
	l = ft_intlen(n, 0);
	p = malloc(sizeof(char) * (l + 1));
	if (!p)
		return (NULL);
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		k = -n;
		p[0] = '-';
	}
	p[l] = '\0';
	while (k)
	{
		p[--l] = '0' + (k % 10);
		k /= 10;
	}
	return (p);
}
