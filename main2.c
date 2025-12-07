#include <stdio.h>

void	increment(int *n)
{
	(*n) += 1;
}

int	main(void)
{
	int	a;

	a = 0;
	while (a < 10)
	{
		printf("%d", a);
		increment(&a);
	}
}
