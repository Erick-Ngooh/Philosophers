/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:20:23 by engooh            #+#    #+#             */
/*   Updated: 2021/11/30 17:22:31 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > len || start > i)
		return ((char *)ft_calloc(sizeof(char), 1));
	if (len >= i - start)
		p = (char *)malloc(sizeof(char) * (i - start + 1));
	else
		p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = -1;
	while (s[++i + start] && i < len)
		p[i] = s[i + start];
	p[i] = '\0';
	return (p);
}
