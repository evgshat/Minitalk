#include "minitalk.h"

int main(void)
{
	int a;
	char	*res;
	a = 454545;
	printf("%d\n", a);
	res = ft_itoa(a);
	printf("%s", res);
}