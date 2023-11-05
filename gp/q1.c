#include <stdio.h>

void f(int *p, int *q)
{
    p = q;
    *p = 2;
    return;
}

int i = 0, j = 1;
void main()
{
    printf(" Before function call\ni:\t%d\tj:\t%d\n", i, j);
    f(&i, &j);
    printf(" After function call\ni:\t%d\tj:\t%d\n", i, j);
}