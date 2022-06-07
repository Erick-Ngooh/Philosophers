/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:33:22 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 19:39:24 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	d;

	d = 0;
	while (d < n && (dest || src))
		*((unsigned char *)(dest + d++)) = *((unsigned char *)src++);
	return (dest);
}
