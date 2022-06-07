/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:00:17 by engooh            #+#    #+#             */
/*   Updated: 2022/06/07 22:24:52 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/philo_bonus.h"

void	*route(void *arg)
{
	printf("i am thread of child process number {%d}\n", *((int *)arg));
	while (1)
	{
	}
	exit(3);
	return (NULL);
}

void	test(int i)
{
	pthread_t	thid;

	printf("i am child process number: {%d}\n", i);
	pthread_create(&thid, NULL, route, &i);
	printf("hello guys %d\n", i);
	while (1)
	{
	}
	pthread_join(thid, NULL);
	exit(2);
}

int	main(void)
{
	int			s;
	int			i;
	int			pid[10];

	i = -1;
	while (++i < 10)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (1);
		if (!pid[i])
			test(i);
	}
	i = -1;
	while (++i < 10)
	{
		waitpid(pid[i], &s, 0);
		if (WIFEXITED(s))
			printf("exit code %d \n", WEXITSTATUS(s));
	}
	return (0);
}
