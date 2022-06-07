/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:07:06 by engooh            #+#    #+#             */
/*   Updated: 2021/11/30 12:26:40 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	while (dst[dlen] && dlen < size)
		dlen++;
	slen = -1;
	while (src[++slen] && dlen + slen + 1 < size)
		dst[dlen + slen] = src[slen];
	if (slen < size - dlen)
		dst[slen + dlen] = '\0';
	return (ft_strlen(src) + dlen);
}
