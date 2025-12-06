#include <stdio.h>
void increment(int *n)
{
    (*n) += 1;
}

int main()
{
    int a = 0;
    while(a < 10)
    {
        printf("%d", a);
        increment(&a);
    }
}