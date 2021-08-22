/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:37:33 by lcharlet          #+#    #+#             */
/*   Updated: 2021/08/22 16:37:56 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j > 0)
		{
			usleep (50);
			if (message[i] & j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j /= 2;
		}
		usleep (50);
		if (!message[i])
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Wrong arguments\n", 16);
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
