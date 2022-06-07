/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:58:52 by engooh            #+#    #+#             */
/*   Updated: 2022/05/06 11:37:19 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_tabs(void **tabs)
{
	int	i;

	if (!tabs)
		return (0);
	i = -1;
	while (tabs[++i])
		free(tabs[i]);
	free(tabs[i]);
	free(tabs);
	return (1);
}
