#include "pars.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	t_list	*one;
	t_list	*clear;

	fd = open("map.ber", O_RDONLY);
	// if(!fd)
	//     return (1);
	// printf("%d\n", map_verify(fd));
	one = gahter_lines(fd);
	clear = one;
	while (one->content)
	{
		printf("%s\n", (char *)one->content);
		one = one->next;
	}
}
