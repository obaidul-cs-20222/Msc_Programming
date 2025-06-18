#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i = 0, j = 1, k = 1;
    n = i++ && j++ && k++;
    printf("\nn: %d\t i: %d\t j: %d\t k:%d\t", n, i, j, k);

    return 0;
}