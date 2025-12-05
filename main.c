#include "pars.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("map.ber", O_RDONLY);
    printf("%d\n", map_verify(fd));
}