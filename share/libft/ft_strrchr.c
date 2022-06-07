/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:57:42 by engooh            #+#    #+#             */
/*   Updated: 2021/11/30 17:21:23 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)(s + i));
	while (i--)
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}
