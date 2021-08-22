/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:37:10 by lcharlet          #+#    #+#             */
/*   Updated: 2021/08/22 17:17:10 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*int_char(int sign, int cnt, long n)
{
	int		ost;
	char	*str;

	ost = 0;
	str = malloc(cnt + 1);
	if (str == 0)
		return (NULL);
	str[cnt] = '\0';
	if (sign == 1)
		str[0] = '-';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (cnt >= 0)
	{
		ost = n % 10;
		str[cnt - 1] = ost + '0';
		n = n / 10;
		if (n == 0)
			break ;
		cnt--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		cnt;
	int		sign;
	long	cpy_n;
	char	*str;

	sign = 0;
	cnt = 0;
	cpy_n = n;
	if (n < 0)
	{
		cnt++;
		sign = 1;
		cpy_n = cpy_n * (-1);
	}
	else if (n == 0)
		cnt = 1;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	str = int_char(sign, cnt, cpy_n);
	return (str);
}


int	ft_atoi(const char *string)
{
	int				i;
	int				sign;
	long int		res;

	i = 0;
	res = 0;
	sign = 0;
	if ((string[i] < '0' || string[i] > '9')
		&& (string[i] < '\t' || string[i] > '\r')
		&& (string[i] != ' ') && (string[i] != '-') && (string[i] != '+'))
		return (0);
	while ((string[i] >= '\t' && string[i] <= '\r') || (string[i] == ' ')
		|| (string[i] == '0'))
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
		res = res * 10 + (string[i++] - '0');
	if (sign == -1)
		return (res * sign);
	return ((int)res);
}

static int	num_int	(int n)
{
	int	cnt;

	cnt = 0;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

static long	f_stepen(int cnt)
{
	long	stepen;

	stepen = 1;
	while (cnt != 1)
	{
		stepen = stepen * 10;
		cnt--;
	}
	return (stepen);
}

static void	res(int cpy_n, int fd, int cnt)
{
	int		ch_int;
	char	ch;
	int		i;
	int		stepen;

	i = 0;
	ch_int = 0;
	stepen = f_stepen(cnt);
	while (stepen != 0)
	{
		ch_int = cpy_n / stepen;
		ch = ch_int + '0';
		cpy_n = cpy_n - ch_int * stepen;
		stepen = stepen / 10;
		write (fd, &ch, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		cnt;
	int		cpy_n;

	cpy_n = n;
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (n == INT_MIN || n == INT_MAX)
	{
		if (n == INT_MIN)
			write (fd, "-2147483648", 11);
		if (n == INT_MAX)
			write (fd, "2147483647", 10);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		cpy_n = n * (-1);
	}
	cnt = num_int(n);
	res(cpy_n, fd, cnt);
}

void	new_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
