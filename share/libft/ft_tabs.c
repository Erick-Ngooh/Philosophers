/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:27:25 by engooh            #+#    #+#             */
/*   Updated: 2022/05/06 11:33:21 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_tabs(int size, int len)
{
	void	*t;

	if (len < 0)
		return (NULL);
	t = malloc(size * (len + 1));
	if (!t)
		return (NULL);
	((unsigned char *)t)[len] = 0;
	return (t);
}
