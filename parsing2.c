#include "utils.h"
#include <stdio.h>

int check_line_length(char *line, int len)
{
    int line_len = ft_strlen(line);
    if(line_len != len)
        return 0;
    return 1;
}