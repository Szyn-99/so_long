#include "pars.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("map.ber", O_RDONLY);
    // if(!fd)
    //     return 1;
    // printf("%d\n", map_verify(fd));
    t_list *one = gahter_lines(fd);
    t_list *clear = one;

    while(one->content)
    {
        printf("%s\n", (char *)one->content);
        one = one->next;
    }
}