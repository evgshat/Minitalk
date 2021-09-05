/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:28:25 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/05 16:28:29 by lcharlet         ###   ########.fr       */
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
