/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:26:53 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 19:26:59 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstadd_back(&((*alst)->next), new);
		else
			(*alst)->next = new;
	}
	else
		*alst = new;
}
