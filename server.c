/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:37:23 by lcharlet          #+#    #+#             */
/*   Updated: 2021/08/22 17:34:24 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pidd(int pid)
{
	char *res;

	printf("%d\n", 123);
	printf("%d\n", pid);
	res = ft_itoa(pid);
	printf("%s", res);
}

void	print_pid(int pid)
{
	char *res;

	// res = ft_itoa(pid);
	printf("%d", 123);
	printf("%s", res);
}

void	one(int signal)
{
	static int	cnt;
	static int	ch;
	static int	i;

	if (cnt == 0)
		cnt = 128;
	if (signal == SIGUSR1)
	{
		ch += cnt;
		cnt /= 2;
		i++;
	}
	else
	{
		cnt /= 2;
		i++;
	}
	if (i == 8)
	{
		if (ch != 0)
		{
			write(1, &ch, 1);
		}
		else
			write(1, "\n", 1);
		cnt = 128;
		ch = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	print_pidd(pid);
	signal(SIGUSR1, &one);
	signal(SIGUSR2, &one);
	while (1)
	{
		pause();
	}
}
