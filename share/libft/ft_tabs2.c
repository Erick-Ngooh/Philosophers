/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:27:54 by engooh            #+#    #+#             */
/*   Updated: 2022/04/05 10:33:10 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabs2(int size1, int len1, int size2, int len2)
{
	int		i;
	void	**t;

	t = malloc(size1 * len1);
	if (!t)
		return (NULL);
	i = -1;
	while (++i < len1)
	{
		t[i] = malloc(size2 * len2);
		if (!t[i])
			return (NULL);
	}
	t[i] = 0;
	return (t);
}
