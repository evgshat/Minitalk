#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

typedef struct s_stack
{
	char		message[100];
}	t_stack;

char	*ft_strdup(const char *str);
int		ft_atoi(const char *string);
char	*ft_itoa(int n);

#endif