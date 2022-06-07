/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:35:36 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 18:56:12 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	char	*p;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	p = malloc((l + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[l] = '\0';
	while (--l >= 0)
		p[l] = f((unsigned int)l, s[l]);
	return (p);
}
