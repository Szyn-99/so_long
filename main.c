#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	t_list	*one;
	t_list	*clear;
	int		a;

	fd = open("map.ber", O_RDONLY);
	a = map_verify(fd);
	printf("map status = %d\n", a);
}
