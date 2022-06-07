/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:48:06 by engooh            #+#    #+#             */
/*   Updated: 2021/11/30 16:48:40 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if ((unsigned char)*s++ == (unsigned char)c)
			return ((char *)--s);
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
