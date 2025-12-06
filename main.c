#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	t_list	*one;
	t_list	*clear;

	fd = open("map.ber", O_RDONLY);

	int a = map_verify(fd);
	printf("%d\n", a);

}
