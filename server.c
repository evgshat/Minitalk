/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:37:23 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/03 16:09:28 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(int pid)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_itoa(pid);
	while (res[i] != '\0')
	{
		write(1, &res[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	handler(int signal)
{
	static int	cnt;
	static int	ch;
	static int	i;

	if (cnt == 0)
		cnt = 128;
	if (signal == SIGUSR1)
		ch += cnt;
	cnt /= 2;
	i++;
	if (i == 8)
	{
		if (ch != 0)
			write(1, &ch, 1);
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
	print_pid(pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
	{
		pause();
	}
}
