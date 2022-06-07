/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:57:24 by engooh            #+#    #+#             */
/*   Updated: 2021/11/29 21:10:44 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*little)
		return ((char *)big);
	i = -1;
	n = ft_strlen(little);
	while (big[++i] && i + n <= len)
		if (!ft_strncmp(big + i, little, n))
			return ((char *)big + i);
	return (NULL);
}
