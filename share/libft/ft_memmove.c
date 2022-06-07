/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:34:00 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 19:39:45 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = dest;
	if (!dest && !src)
		return (NULL);
	if (d > (unsigned char *)src)
		while (n--)
			*(d + n) = *((unsigned char *)src + n);
	else
		while (n--)
			*d++ = *((unsigned char *)src++);
	return (dest);
}
