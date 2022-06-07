/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:32:42 by engooh            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:25 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	if (n == 0)
		return (0);
	p1 = s1;
	p2 = s2;
	while (*p1++ == *p2++ && n - 1)
		n--;
	return (*--p1 - *--p2);
}
